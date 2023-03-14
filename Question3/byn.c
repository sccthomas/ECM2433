#include "byn.h"

/**
 * This program will calculate statistics for 2-N players in separate Beggar games. It will calculate the shortest,
 * longest and average turns for each game simulated. The program takes in an argument for the the max players and how
 * many times the game should be simulated at each player amount.
 * @param argc
 * @param argv
 * @return it will output to the console the statistics calculated for the games
 */
int main(int argc, char **argv){
    if(argc==1){
        return 1;
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
    return 0;
}

/**
 * This function will play a game of beggar your neighbour from 0 to games. Over these games it will calculate the
 * shortest, longest, and average turns at the end of all game executions.
 * @param Nplayers
 * @param games
 * @return
 */
STATS* statistics(int Nplayers, int games){
    STATS *game_stats = (STATS *)malloc(sizeof(STATS));
    if(game_stats == NULL){
        printf("Insufficient memory\n");
        exit(-1);
    }
    game_stats->longest=0; // Set to 0 so it can increase
    game_stats->shortest=INT_MAX; // Set to INT_MAX so it can decrease
    game_stats->average = 0;
    int i;
    int turns;
    for (i = 0; i < games; ++i) {
        int deck[52] ={ 2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                        2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                        2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14 ,
                        2 , 3 , 4 , 5 , 6 , 7 , 8, 9 , 10 , 11 , 12 , 13 , 14};
        shuffle(deck, 52, -1);
        turns = beggar(Nplayers, deck, 0);
        game_stats->average+=turns;
        if(turns > game_stats->longest){ // If turns is greater than the current longest then set as longest
            game_stats->longest = turns;
        }
        if(turns < game_stats->shortest){ // If turns is less than the current shortest then set as shortest
            game_stats->shortest = turns;
        }
    }
    game_stats->average/=games; // Calculate the average turns over the games
    return game_stats;
}