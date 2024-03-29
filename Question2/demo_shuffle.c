#include "demo_shuffle.h"

/**
 * This program shows examples of the riffle function. It executes both a riffle_once and a riffle(x amount) on the
 * data structures numbers and greek. Outputted to the console will be clearly labelled sections specifying what each
 * output is.
 * @return
 */
int main(){
    // Set the random seed
    srand(time(0));
    int i;
    int j;
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20};
    int numbers_size = sizeof(numbers) / sizeof (numbers[0]);
    int *numbers_work = (int *)malloc(numbers_size * sizeof (int ));
    // Check if the malloc was successful
    if(numbers_work == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    printf("Riffle once Numbers: \n");
    // Run riffle_once on numbers
    riffle_once(numbers, numbers_size, sizeof (int), numbers_work);
    for (i = 0; i < numbers_size; ++i) {
        printf(" %d |",numbers[i]);
    }
    free(numbers_work);
    printf("\n");
    printf("Riffle Numbers 5 times: \n");
    // Run riffle 5 on numbers
    riffle(numbers,numbers_size,sizeof (int),5);
    for (i = 0; i < numbers_size; ++i) {
        printf(" %d |",numbers[i]);
    }
    printf("\n");
    int numbers_copy[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20};
    int numbers_size_copy = sizeof(numbers_copy) / sizeof (numbers_copy[0]);
    int check_shuffle_numbers = check_shuffle(numbers_copy,numbers_size_copy,sizeof (numbers_copy[0]),cmp_integer);
    printf("Numbers shuffle check = %d\n",check_shuffle_numbers);
    printf("\n");

    //////////////////////////////////////

    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu"};
    int greek_size = sizeof(greek) / sizeof (greek[0]);
    void *work = malloc(greek_size * sizeof (greek[0]));
    // Check if the malloc was successful
    if(work == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    printf("Riffle Greek numbers :\n");
    // Run riffle_once on greek
    riffle_once(greek, greek_size, sizeof (greek[0]), work);
    memcpy(greek,work,(sizeof (greek[0])*greek_size));
    for (j = 0; j < greek_size; ++j) {
        printf(" %s |",greek[j]);
    }
    printf("\n");
    free(work);
    printf("Riffle Greek 5 times: \n");
    // Run riffle 5 on greek
    riffle(greek,greek_size,sizeof (greek[0]),5);
    for (j = 0; j < greek_size; ++j) {
        printf(" %s |",greek[j]);
    }
    printf("\n");

    char *greek_copy[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu" };
    int greek_size_copy = sizeof(greek_copy) / sizeof (greek_copy[0]);
    int check_shuffle_greek = check_shuffle(greek_copy,greek_size_copy,sizeof (greek_copy[0]),cmp_string);
    printf("Greek shuffle check = %d\n",check_shuffle_greek);

    return 0;
}






















