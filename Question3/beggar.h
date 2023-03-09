#include <stdlib.h>
#include <stdio.h>

typedef struct queueStruct
{
    char data;
    struct queueStruct *nextNode;
}QUEUE;

int beggar(int Nplayers, int *deck, int talkative);
void round_robin_cards(int *deck, int **decks, int players,int deck_length);

//int finished(int *players, int Nplayers);




QUEUE *newNode (char);
void printStack(QUEUE*);
void enqueue(QUEUE*,QUEUE**);
char dequeue(QUEUE **);
