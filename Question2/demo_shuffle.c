#include "demo_shuffle.h"

int main(){
    int pack_size;
    int i;
    printf("Testing rifle once\n");
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    pack_size = sizeof(numbers) / sizeof (numbers[0]);
    int *work = (int*)malloc(pack_size * sizeof (int ));

    riffle_once(numbers, pack_size, sizeof (int), work);
    for (i = 0; i < pack_size; ++i) {
        printf("%d \n",work[i]);
    }
    free(work);

    printf("Testing rifle\n");
    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu" };
    pack_size = sizeof(greek) / sizeof (greek[0]);
    riffle(greek,pack_size,sizeof (greek[0]),5);
    for (i = 0; i < pack_size; ++i) {
        printf("%s \n",greek[i]);
    }

    printf("Testing check shuffle\n");
    char *greek1[] = {"alpha", "beta", "gamma", "delta", "epsilon",
                     "zeta", "eta", "theta", "iota", "kappa", "lambda", "mu" };
    pack_size = sizeof(greek1) / sizeof (greek1[0]);
    int check_greek = check_shuffle(greek1,pack_size,sizeof (greek1[0]),cmp_string);
    printf("Greek = %d \n",check_greek);


    int numbers1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    pack_size = sizeof(numbers1) / sizeof (numbers1[0]);
    int check_num = check_shuffle(numbers1,pack_size,sizeof (numbers1[0]),cmp_integer);
    printf("Numbers = %d \n",check_num);

    return 1;
}
