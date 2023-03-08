#include "quality.h"

int main(){
    printf("%d",quality_method());
    return 1;
}

int quality_method(){
    // find which average is the best using 1-15 shuffles.
    float average;
    int best_N;
    float best_Average = 0;
    int i;
    for (i = 1; i < 16; ++i) {
        average = average_quality(50,i,30);
        if(average>best_Average){
            best_Average = average;
            best_N = i;
        }
    }
    printf("best = %f \n",best_Average);
    printf("%d \n",best_N);
    return best_N;
}