#include "beggar.h"



int main(){
    int deck[52] ={2,3,4,5,6,7,8,9,10,11,12,13,14,
                   2,3,4,5,6,7,8,9,10,11,12,13,14,
                   2,3,4,5,6,7,8,9,10,11,12,13,14,
                   2,3,4,5,6,7,8,9,10,11,12,13,14};
    int i;
    int card_num = 0;
    beggar(2, deck, 0);
    return 0;
}

void round_robin_cards(int *deck, PLAYER *players, int Nplayers, int deck_length){
    int i, j = 0, k = 0;
    int count = 0;
    int extra = deck_length%Nplayers;
    //printf("extra = %d \n", extra);
    while(count<deck_length-extra) {
        for (i = 0;  i< Nplayers; i++) {
            enqueue(&players[i].hand,deck[count],&players[i].hand_size);
            count++;
        }
        j+=1;
    }
    while(count<deck_length) {
        enqueue(&players[k].hand,deck[count],&players[k].hand_size);
        count++;
        k+=1;
    }
}

int beggar(int Nplayers, int *deck, int talkative){
    PLAYER players[Nplayers];
    QUEUE pile; //The centre pile
    pile.front= NULL;
    pile.rear = NULL;
    int deck_size = 52;
    int current_player = 0;
    int i;
    for (i = 0; i < Nplayers; ++i) {
        PLAYER *player = &players[i];
        player->id = i;
        player->hand.front = NULL;
        player->hand.rear = NULL;
        player->hand_size = 0;
    }
    round_robin_cards(deck,players,Nplayers,deck_size);
    //dequeue(&players[0].hand,&players[0].hand_size);
    for (i = 0; i < Nplayers; ++i) {
        print_hand( &players[i].hand);
    }
    int won = finished(players,Nplayers);
    while(won == 0){
        won = finished(players,Nplayers);
        int current_player_card = dequeue(&players[current_player].hand,&players[current_player].hand_size);
        if(current_player_card > 10){
            //penalty stuff
        }

    }
    return 0;
}

int take_turn(QUEUE *player, QUEUE *pile){
    QUEUE_ITEM *player_card = player->front;
    int player_card_value = player_card->data;
    // 11 = Jack, 12 = Queen, 13 = King and 14 = Ace
    // 4 cards for an Ace, 3 for a King, 2 cards for a Queen and 1 for a Jack.
    if(player_card_value > 10){ // Penalty card
        if(player_card_value == 11){
            return 4;
        }
    }
    return 0;
}

int finished(PLAYER *players, int Nplayers){
    int i;
    for (i = 0; i < Nplayers; ++i) {
        if(players->hand_size==52){
            return 1;
        }
    }
    return 0;
}


//////////////// Queue stuff ////////////////

void print_hand(QUEUE *deck){
    QUEUE_ITEM *card = deck->front;
    while(card!=NULL){
        printf("%d ",card->data);
        card = card->nextNode;
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
        exit(1);
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

