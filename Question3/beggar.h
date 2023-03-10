#include <stdlib.h>
#include <stdio.h>

typedef struct queueItem {
    int data;
    struct queueItem *nextNode;
}QUEUE_ITEM;

typedef struct Queue {
    struct queueItem* front;
    struct queueItem* rear;
}QUEUE;

typedef struct Player {
    int id;
    struct Queue hand;
    int hand_size;
}PLAYER;

void enqueue(QUEUE *deck, int card, int *hand_size);
int dequeue(QUEUE *deck, int *hand_size);
void print_hand(QUEUE *deck);


int beggar(int Nplayers, int *deck, int talkative);
int finished(PLAYER *players, int Nplayers);
int take_turn(QUEUE *player, QUEUE *pile);

void round_robin_cards(int *deck, PLAYER *players, int Nplayers, int deck_length);