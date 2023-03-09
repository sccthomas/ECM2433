#include "quality.h"

int main(){
    quality_method();
    return 0;
}

void quality_method(){
    // find which average is the best using 1-15 shuffles.
    float average;
    float overall = 0;
    int i;
    for (i = 1; i < 16; ++i) {
        average = average_quality(50,i,30);
        printf("Average Quality with %d shuffles = %f\n",i,average);
        overall+=average;
    }
    printf("Average over shuffles 1-15 = %f\n",overall/15);
}