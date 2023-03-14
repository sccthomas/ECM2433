#include "beggar.h"

/**
 * This function will distribute a deck of cards to an array of players in a round-robin fashion
 * @param deck The deck that needs to be distributed
 * @param players The array of players
 * @param Nplayers The amount of players
 * @param deck_length The length of the deck
 */
void round_robin_cards(int *deck, PLAYER *players, int Nplayers, int deck_length){
    int i, j = 0, k = 0;
    int count = 0;
    int extra = deck_length%Nplayers; // Calculate how many extra cards there are if odd number of players
    while(count<deck_length-extra) {
        for (i = 0;  i< Nplayers; i++) {
            PLAYER *player = &players[i];
            enqueue(player->hand,deck[count],&(player->hand->hand_size));
            count++;
        }
        j+=1;
    }
    // Distribute the leftover cards if there are some left
    while(count<deck_length) {
        PLAYER *player = &players[k];
        enqueue(player->hand,deck[count],&(player->hand->hand_size));
        count++;
        k+=1;
    }
}

/**
 * This function beggar will execute one game of beggar your neighbour. It will initiate player structs and queue
 * queue structs for the various data items that require this data structure. After this setup the game will then occur
 * while no player has won. The function will return the number of turns taken for the game to finish. The function has
 * the option to output the steps of the game
 * @param Nplayers The number of players in the game
 * @param deck The deck the game is using
 * @param talkative 1 or 0, 1 output the steps and 0 stay quiet.
 * @return The total turns when the game ended
 */
int beggar(int Nplayers, int *deck, int talkative) {
    PLAYER players[Nplayers]; // The array of players in the game
    QUEUE *pile = initializeQueue(); // A queue representing the middle pile that players add to
    int deck_size = 52;
    int current_player = 0; // Index for the current player
    int previous_player_index = Nplayers-1; // Index for the previous player
    int i, k, turns = 1;
    // Loop through all players and create a QUEUE hand to represent the cards they hold
    for (i = 0; i < Nplayers; ++i) {
        PLAYER *player = &players[i];
        player->id = i;
        player->hand = initializeQueue();
    }
    round_robin_cards(deck, players, Nplayers, deck_size); // Distribute the cards to the players
    if(talkative != 0){
        print_decks(Nplayers,players,current_player);
    }
    int won = finished(players, Nplayers); // Check if anyone has won the game
    while (won == 0) {
        PLAYER *player_turn = &players[current_player]; // Get the player whose turn it is
        won = finished(players, Nplayers);
        if(talkative != 0){ // Output game info if talkative
            printf("Turn %d\n",turns);
            printf("Pile: ");
            print_hand(pile);
            print_decks(Nplayers,players, current_player);
        }
        if(player_turn->hand->front == NULL){ // If the player has no cards then skip and increment the current player
            current_player = (current_player + 1) % Nplayers;
            turns += 1;
            continue;
        }
        QUEUE *reward = take_turn(player_turn->hand, pile); // If the player can play then take a turn
        if (reward != NULL) { // The pile top is penalty card so the previous player has to pay
            PLAYER *previous_player = &players[previous_player_index];
            while(reward->front!=NULL) { // Put reward on the players deck
                int reward_card = dequeue(reward, &(reward->hand_size));
                enqueue(previous_player->hand,reward_card,&(previous_player->hand->hand_size));
            }
            free(reward);
        }
        previous_player_index = current_player; // Current player has played so make then the previous player
        current_player = (current_player + 1) % Nplayers; // Increment the current player
        turns += 1;
        if(turns>4999){
            break;
        }
    }
    // The game has ended, so we must free all items and hands
    for (k = 0; k < Nplayers; ++k) {
        PLAYER *player = &players[k];
        freeDeck(player->hand);
    }
    freeDeck(pile);
    return turns;
}

/**
 * This function takes in a card value and return the cost of the card if it is a penalty card
 * @param card The card being assessed
 * @return The cost of the card given
 */
int is_penalty_card(int card){
    int cost = 0;
    // 11 = Jack, 12 = Queen, 13 = King and 14 = Ace
    // 4 cards for an Ace, 3 for a King, 2 cards for a Queen and 1 for a Jack.
    if(card > 10) { // Penalty card on pile
        if (card == 11) {
            cost = 1;
        } else {
            if (card == 12) {
                cost = 2;
            } else {
                if (card == 13) {
                    cost = 3;
                } else {
                    if (card == 14) {
                        cost = 4;
                    }
                }
            }
        }
    }
    return cost;
}

/**
 * This function will cause the player to take a turn in the beggar game. The turn is dependent on the piles top. If the
 * pile is empty the player will just add one card and return NULL meaning no cost. If the the pile has a penalty card
 * on it then the player will prepare to pay the cost. But if they have a penalty card within the cost they must pay
 * then they can stop during the payment of the cost to the pile. If there is a successful cost then the pile is updated
 * with the players cost cards and then a new QUEUE is made to hold the pile cards and the pile is emptied.
 * @param player The players deck whose turn it is
 * @param pile The centre pile
 * @return The reward, either being a QUEUE or NULL
 */
QUEUE* take_turn(QUEUE *player, QUEUE *pile){
    int current_player_card;
    int i;
    if(pile->front == NULL){ // If the pile is empty
        current_player_card = dequeue(player,&(player->hand_size));
        enqueue(pile,current_player_card,&pile->hand_size);
        return NULL;
    }else{ // The pile has a card on it
        int cost = is_penalty_card(pile->rear->data);
        if(cost==0){ // The pile top is not a penalty card
            current_player_card = dequeue(player,&(player->hand_size));
            enqueue(pile,current_player_card,&(pile->hand_size));
            return NULL;
        }else{ // The pile has a penalty card on top of it
            for (i = 0; i < cost; ++i) {
                if(player->front == NULL){ // The player has no cards left after the cost
                    break;
                }
                current_player_card = dequeue(player,&(player->hand_size));
                enqueue(pile,current_player_card,&(pile->hand_size));
                if(is_penalty_card(current_player_card) != 0) { // If the player has a penalty card in their hand
                    return NULL;
                }
            }
            QUEUE *reward = initializeQueue(); // The reward being given to the previous player
            while(pile->front!=NULL){ // Empty the pile QUEUE and add to the reward QUEUE
                current_player_card = dequeue(pile,&(pile->hand_size));
                enqueue(reward,current_player_card,&(reward->hand_size));
            }
            return reward;
        }
    }
}

/**
 * This function will check if an player has a hand of length 52, meaning they have won the game
 * @param players The players array
 * @param Nplayers The amount of players
 * @return If a player has won, 1 = True, 0 = False
 */
int finished(PLAYER *players, int Nplayers){
    int i;
    for (i = 0; i < Nplayers; ++i) {
        PLAYER *player = &players[i];
        if(player->hand->hand_size==52){
            return 1;
        }
    }
    return 0;
}

//////////////// Queue stuff ////////////////

/**
 * This function will print the hand of a player
 * @param deck The deck being printed
 */
void print_hand(QUEUE *deck){
    QUEUE_ITEM *card = deck->front;
    while(card!=NULL) {
        printf("%d, ", card->data);
        card = card->nextNode;
    }
    printf("\n");

}

/**
 * This function will output the hands of each player who is playing the beggar game
 * @param Nplayers The amount of players
 * @param players The players array containing all player structs
 * @param current_player The current player so we know where to put a *
 */
void print_decks(int Nplayers, PLAYER *players, int current_player){
    int i;
    for (i = 0; i < Nplayers; ++i) {
        if(i == current_player){ // If they are the current player put a * by their deck
            printf("*   %d: ",i);
        }
        else{
            printf("    %d: ",i);
        }
        PLAYER *player = &players[i];
        print_hand(player->hand);
    }
    printf("\n");
}

/**
 * This function will add an item to the hand of a player (their QUEUE)
 * @param deck The QUEUE deck being added to
 * @param card The card being added to the QUEUE
 * @param hand_size The current size of their QUEUE
 */
void enqueue(QUEUE *deck, int card, int *hand_size) {
    QUEUE_ITEM* newNode; // Make a new queue item
    if (!(newNode = (QUEUE_ITEM*)malloc(sizeof(QUEUE_ITEM)))) {
        printf("malloc failed\n");
        exit(-1);
    }
    newNode->data = card;
    newNode->nextNode = NULL;
    if(deck->front == NULL){ // If the deck is empty then set new item as front and end
        deck->front = newNode;
        deck->rear = newNode;
    }else{ // If the deck already has contents then add to the rear
        deck->rear->nextNode = newNode;
        deck->rear = newNode;
    }
    (*hand_size)++; // Increment the hand size
}

/**
 * This function will remove an item from a given deck and return its value
 * @param deck The deck being dequeued
 * @param hand_size The decks size
 * @return The card value that was removed from the deck
 */
int dequeue(QUEUE *deck, int *hand_size){
    if(deck->front==NULL){ // Deck is empty
        return 0;
    }
    QUEUE_ITEM *removed = deck->front;
    int card = removed->data;
    if(deck->front==deck->rear){ // The deck is now empty
        deck->front = NULL;
        deck->rear = NULL;
    }else{ // Set the front as the old nodes rear
        deck->front = deck->front->nextNode;
    }
    free(removed);
    (*hand_size)--; // Decrease the hand size
    return card;
}

/**
 * This function is used to create a new QUEUE and return a pointer to it
 * @return A pointer to the created QUEUE
 */
QUEUE* initializeQueue() {
    QUEUE *deck = (QUEUE *)malloc(sizeof(QUEUE));
    if(deck == NULL){
        printf("Insufficient memory\n");
        exit(-1);
    }
    deck->front = NULL;
    deck->rear = NULL;
    deck->hand_size = 0;
    return deck;
}

/**
 * This function is used to empty and free a QUEUE with its QUEUE items
 * @param deck
 */
void freeDeck(QUEUE *deck) {
    while (deck->front != NULL) {
        dequeue(deck, &(deck->hand_size));
    }
    free(deck);
}
