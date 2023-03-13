#include "beggar.h"



int main(){
    int deck[52] ={ 3 , 4 , 2 , 3 , 5 , 6 , 7 , 8 , 4 , 9 , 5 , 10 , 6 ,
                    11 , 12 , 7 , 8 , 13 , 9 , 14 , 2 , 10 , 11 , 3 ,
                    4 , 5 , 12 , 13 , 14 , 2 , 6 , 3 , 4 , 7 , 5 , 6 ,
                    7 , 8 , 9 , 8 , 9 , 10 , 11 , 10 , 11 , 12 , 13 , 12 ,
                    13 , 14 , 14 , 2 };
    int turns = beggar(4, deck, 1);
    printf("turns = %d",turns);
    return 0;
}

void round_robin_cards(int *deck, PLAYER *players, int Nplayers, int deck_length){
    int i, j = 0, k = 0;
    int count = 0;
    int extra = deck_length%Nplayers;
    //printf("extra = %d \n", extra);
    while(count<deck_length-extra) {
        for (i = 0;  i< Nplayers; i++) {
            PLAYER *player = &players[i];
            enqueue(player->hand,deck[count],&(player->hand->hand_size));
            count++;
        }
        j+=1;
    }
    while(count<deck_length) {
        PLAYER *player = &players[i];
        enqueue(player->hand,deck[count],&(player->hand->hand_size));
        count++;
        k+=1;
    }
}

int beggar(int Nplayers, int *deck, int talkative) {
    PLAYER players[Nplayers];
    QUEUE *pile = initializeQueue();
    int deck_size = 52;
    int current_player = 0;
    int previous_player_index = Nplayers-1;
    int i, j, turns = 1;
    for (i = 0; i < Nplayers; ++i) {
        PLAYER *player = &players[i];
        player->id = i;
        player->hand = initializeQueue();
    }
    round_robin_cards(deck, players, Nplayers, deck_size);
    print_decks(Nplayers,players,current_player);
    int won = finished(players, Nplayers);
    while (won == 0) {
        PLAYER *player_turn = &players[current_player];
        won = finished(players, Nplayers);

        printf("Turn %d\n",turns);
        printf("Pile: ");
        print_hand(pile);
        print_decks(Nplayers,players, current_player);

        if(player_turn->hand->front == NULL){
            printf("No cards \n");
            current_player = (current_player + 1) % Nplayers;
            turns += 1;
            continue;
        }
        QUEUE *reward = take_turn(player_turn->hand, pile);
        if (reward != NULL) { // the pile top is penalty card so the previous player has to pay
            PLAYER *previous_player = &players[previous_player_index];
            while(reward->front!=NULL) { //put reward on the players deck
                int reward_card = dequeue(reward, &(reward->hand_size));
                enqueue(previous_player->hand,reward_card,&(previous_player->hand->hand_size));
            }
        }
        previous_player_index = current_player;
        current_player = (current_player + 1) % Nplayers;
        turns += 1;
        if(turns>4999){
            break;
        }
    }
    return turns;
}

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

QUEUE* take_turn(QUEUE *player, QUEUE *pile){
    int current_player_card;
    int i;
    if(pile->front == NULL){
        current_player_card = dequeue(player,&(player->hand_size));
        enqueue(pile,current_player_card,&pile->hand_size);
        return NULL;
    }else{
        int cost = is_penalty_card(pile->rear->data);
        if(cost==0){
            current_player_card = dequeue(player,&(player->hand_size));
            enqueue(pile,current_player_card,&(pile->hand_size));
            return NULL;
        }else{
            for (i = 0; i < cost; ++i) {
                if(player->front == NULL){
                    break;
                }
                current_player_card = dequeue(player,&(player->hand_size));
                enqueue(pile,current_player_card,&(pile->hand_size));
                if(is_penalty_card(current_player_card) != 0) {
                    return NULL;
                }
            }
            QUEUE *reward = initializeQueue();
            printf("\npile after reward ");
            print_hand(pile);
            while(pile->front!=NULL){
                current_player_card = dequeue(pile,&(pile->hand_size));
                enqueue(reward,current_player_card,&(reward->hand_size));
            }
            return reward;
        }
    }
}

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

void print_hand(QUEUE *deck){
    QUEUE_ITEM *card = deck->front;
    while(card!=NULL) {
        printf("%d, ", card->data);
        card = card->nextNode;
    }
    printf("    Hand size = %d",deck->hand_size);
    printf("\n");

}

void print_decks(int Nplayers, PLAYER *players, int current_player){
    int i;
    printf("Hands \n");
    for (i = 0; i < Nplayers; ++i) {
        if(i == current_player){
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

void enqueue(QUEUE *deck, int card, int *hand_size) {
    QUEUE_ITEM* newNode;
    if (!(newNode = (QUEUE_ITEM*)malloc(sizeof(QUEUE_ITEM)))) {
        printf("malloc failed\n");
        exit(1);
    }
    newNode->data = card;
    newNode->nextNode = NULL;
    if(deck->front == NULL){
        deck->front = newNode;
        deck->rear = newNode;
    }else{
        deck->rear->nextNode = newNode;
        deck->rear = newNode;
    }
    (*hand_size)++;
}

int dequeue(QUEUE *deck, int *hand_size){
    if(deck->front==NULL){
        //Deck is empty
        return 0;
    }
    QUEUE_ITEM *removed = deck->front;
    int card = removed->data;
    if(deck->front==deck->rear){
        //empty now
        deck->front = NULL;
        deck->rear = NULL;
    }else{
        deck->front = deck->front->nextNode;
    }
    free(removed);
    (*hand_size)--;
    return card;
}

QUEUE* initializeQueue() {
    QUEUE *deck = (QUEUE *)malloc(sizeof(QUEUE));
    deck->front = NULL;
    deck->rear = NULL;
    deck->hand_size = 0;
    return deck;
}

