#include "single.h"

/**
 * This function will start a single game of beggar your neighbour and output the turns taken along with the steps in
 * the game
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv){
    if(argc==1){
        return 1;
    }
    int deck[52] ={ 2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                    2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                    2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                    2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14};
    int Nplayers = atoi(argv[1]);
    shuffle(deck, 52, -1);
    int turns = beggar(Nplayers, deck, 1);
    printf("turns = %d\n",turns);
    return 0;
}