#include "beggar.h"




int main(){
    int deck[52];
    int i;
    for (i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }
    beggar(5, deck, 0);
    return 0;
}

void round_robin_cards(int *deck, int **decks, int Nplayers, int deck_length){
    int i, j = 0, k = 0;
    int count = 0;
    int cards_to_player = deck_length/Nplayers;
    //printf("cards to player %d\n",cards_to_player);
    int extra = deck_length%Nplayers;
    //printf("extra = %d \n", extra);
    while(count<deck_length-extra) {
        for (i = 0;  i< Nplayers; i++) {
            decks[i][j] = deck[count];
            count++;
        }
        j+=1;
    }
    //printf("count = %d \n", count);
    while(count<deck_length) {
        decks[k][j] = deck[count];
        //printf("decks = %d \n", decks[i][j]);
        count++;
        k+=1;
    }

}



int beggar(int Nplayers, int *deck, int talkative){
    // Make all the players and give them all cards, shuffle the cards once you can give them all cards
    int **decks = (int **) malloc(sizeof (int *) * Nplayers); //2D array containing Nplayers hands.
    int i;
    int deck_size = 52;
    int decks_size = deck_size/Nplayers + 1;
    for (i = 0; i < Nplayers; ++i) {
        decks[i] = (int*) malloc(sizeof (int)*(decks_size));
    }
    round_robin_cards(deck,decks,Nplayers,deck_size); // Distribute the cards;
    for (int k = 0; k < Nplayers; ++k) {
        for (int l = 0; l < decks_size; ++l) {
            printf("%d ",decks[k][l]);
        }
        printf("\n");
    }
    return 0;
}



//int finished(int *players, int Nplayers){}






//int main()
//{
//    STACK *root = NULL;
//    STACK *new_Node = newNode('Q');
//    STACK *new_Node_2 = newNode('C');
//    push(new_Node,&root);
//    push(new_Node_2,&root);
//    pop(&root);
//
//}

QUEUE *newNode(char c)
{
    QUEUE *nNode = malloc(sizeof(QUEUE));
    nNode->data = c;
    return nNode;
}

void printStack(QUEUE *node)
{
    QUEUE *next = node->nextNode;
    printf("%c to ",node->data);
    if(next != NULL)
    {
        printf("%c\n",next->data);
        printStack(next);
    } else {
        printf("NULL\n");
    }
}

void enqueue(QUEUE *Node, QUEUE **End) {
    Node->nextNode = *End;
    *End = Node;
}

char dequeue(QUEUE **Start){
    char data;
    QUEUE * next_node = NULL;
    if(*Start == NULL){
        return -1;
    }
    next_node = (*Start)->nextNode;
    data = (*Start)->data;
    free(*Start);
    *Start = next_node;
    return data;
}

