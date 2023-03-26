#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct queueItem {
    int data;
    struct queueItem *nextNode;
}QUEUE_ITEM;

typedef struct Queue {
    struct queueItem* front;
    struct queueItem* rear;
    int hand_size;
}QUEUE;

typedef struct Player {
    int id;
    struct Queue *hand;
}PLAYER;

QUEUE *initializeQueue();
void enqueue(QUEUE *deck, int card, int *hand_size);
int dequeue(QUEUE *deck, int *hand_size);
void freeDeck(QUEUE *deck);
void print_hand(QUEUE *deck);
int is_penalty_card(int card);
void print_decks(int Nplayers, PLAYER *players, int current_player);

int beggar(int Nplayers, int *deck, int talkative);
int finished(PLAYER *players, int Nplayers);
QUEUE* take_turn(QUEUE *player, QUEUE *pile);

void round_robin_cards(int *deck, PLAYER *players, int Nplayers, int deck_length);