#include "single.h"


int main(int argc, char **argv){
    if(argc==1){
        return 0;
    }
    int deck[52] ={ 3 , 4 , 2 , 3 , 5 , 6 , 7 , 8 , 4 , 9 , 5 , 10 , 6 ,
                    11 , 12 , 7 , 8 , 13 , 9 , 14 , 2 , 10 , 11 , 3 ,
                    4 , 5 , 12 , 13 , 14 , 2 , 6 , 3 , 4 , 7 , 5 , 6 ,
                    7 , 8 , 9 , 8 , 9 , 10 , 11 , 10 , 11 , 12 , 13 , 12 ,
                    13 , 14 , 14 , 2 };
    int Nplayers = atoi(argv[1]);
    shuffle(deck, 52, -1);
    int turns = beggar(Nplayers, deck, 1);
    printf("turns = %d\n",turns);
    return 1;
}