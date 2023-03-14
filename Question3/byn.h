#include "beggar.h"
#include "shuffle.h"
#include <limits.h>

typedef struct stats {
    int longest;
    int shortest;
    float average;
}STATS;

STATS* statistics(int Nplayers, int games);