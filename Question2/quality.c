#include "quality.h"

/**
 * This program will ca
 * @return If the quality testing is average
 */
int main(){
    srand(time(0)); // Set the random seed
    float average;
    float overall = 0;
    int i;
    // This for loop will calculate the quality for 1-15 shuffles
    for (i = 1; i < 16; ++i) {
        average = average_quality(50,i,30);
        printf("Average Quality with %d shuffles = %f\n",i,average);
        overall+=average;
    }
    printf("Average over shuffles 1-15 = %f\n",overall/15);
    return 0;
}

