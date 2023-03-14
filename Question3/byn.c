#include "byn.h"


int main(int argc, char **argv){
    if(argc==1){
        return 0;
    }
    int Nplayers = atoi(argv[1]);
    int trails = atoi(argv[2]);
    int i;
    for (i = 2; i <= Nplayers; ++i) {
        STATS *stats = statistics(i,trails);
        printf("Game with %d Players Stats: \n",i);
        printf("Shortest = %d\n",stats->shortest);
        printf("Longest = %d\n",stats->longest);
        printf("Average = %f\n",stats->average);
        printf("\n");
        free(stats);
    }
    return 1;
}

STATS* statistics(int Nplayers, int games){
    int deck[52] ={ 3 , 4 , 2 , 3 , 5 , 6 , 7 , 8 , 4 , 9 , 5 , 10 , 6 ,
                    11 , 12 , 7 , 8 , 13 , 9 , 14 , 2 , 10 , 11 , 3 ,
                    4 , 5 , 12 , 13 , 14 , 2 , 6 , 3 , 4 , 7 , 5 , 6 ,
                    7 , 8 , 9 , 8 , 9 , 10 , 11 , 10 , 11 , 12 , 13 , 12 ,
                    13 , 14 , 14 , 2 };
    STATS *game_stats = (STATS *)malloc(sizeof(STATS));
    game_stats->longest=0;
    game_stats->shortest=INT_MAX;
    game_stats->average = 0;
    int i;
    int turns;
    for (i = 0; i < games; ++i) {
        shuffle(deck, 52, -1);
        turns = beggar(Nplayers, deck, 0);
        game_stats->average+=turns;
        if(turns > game_stats->longest){
            game_stats->longest = turns;
        }
        if(turns < game_stats->shortest){
            game_stats->shortest = turns;
        }
    }
    game_stats->average/=games;
    return game_stats;
}