#include "riffle.h"


int main(){

    /*
    int numbers[] =  {0 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                      12, 13, 14, 15, 16, 17, 18, 19, 20};
    int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    printf("%d\n",pack_size);
    int *work = (int*)malloc(pack_size * sizeof (int ));

    riffle_once(numbers, pack_size, sizeof (int), work);
    int i;
    for (i = 0; i < pack_size; ++i) {
        printf("%d \n",work[i]);
    }
    free(work);
     */

    /*
    int pack_size;
    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu","fr" };
    pack_size = sizeof(greek) / sizeof (greek[0]);
    riffle(greek,pack_size,sizeof (greek[0]),7);
    int i;
    for (i = 0; i < pack_size; ++i) {
        printf("%s \n",greek[i]);
    }


    int numbers[] = {0 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                     23, 24, 25, 26, 27, 28, 29,
                     30, 31, 32, 33, 34, 35, 36, 37, 38 ,39 ,
                     40, 41, 42, 43 ,44 ,45 ,46 ,47 ,48 ,49, 50};
    pack_size = sizeof(numbers) / sizeof (numbers[0]);
    riffle(numbers,pack_size,sizeof (numbers[0]),1);
    for (i = 0; i < pack_size; ++i) {
        printf("%d \n",numbers[i]);
    }
    //printf("%f \n",quality(numbers,pack_size));
    */


    /*
    int pack_size;
    char *L[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu"};
    int len = sizeof(L) / sizeof (L[0]);
    int size = sizeof (L[0]);
    void *work = malloc(len * size);
    riffle_once(L, len, size, work);
    memcpy(L,work,(size*len));

    int j;
    for (j = 0; j < len; ++j) {
        printf("%s ",L[j]);
    }
    free(work);
     */
    /*
    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu"};
    int greek_size = sizeof(greek) / sizeof (greek[0]);
    void *work = malloc(greek_size * sizeof (greek[0]));
    riffle_once(greek, greek_size, sizeof (greek[0]), work);
    memcpy(greek,work,(sizeof (greek[0])*greek_size));
    int j;
    for (j = 0; j < greek_size; ++j) {
        printf("%s ",greek[j]);
    }
    free(work);
     */
    /*
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    int good = check_shuffle(numbers,pack_size,sizeof (numbers[0]),cmp_integer);
    printf("%d \n",good);
    return 1;
     */

    //int b = quality_c();
    //printf("%d \n",b);

    //printf("final = %f\n",average_quality(50,1,3));
    //int numbers[] = {0, 1, 2, 3, 4, 5, 6};
    //int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    //int i;
    //printf("%f \n",quality(numbers,pack_size));
    //printf("%f \n",average_quality(50,12,30));
    //quality_c();
    /*
    int i;
    int j;
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20};
    int numbers_size = sizeof(numbers) / sizeof (numbers[0]);
    int *numbers_work = (int *)malloc(numbers_size * sizeof (int ));
    printf("Riffle once Numbers: \n");
    riffle_once(numbers, numbers_size, sizeof (int), numbers_work);
    for (i = 0; i < numbers_size; ++i) {
        printf(" %d |",numbers_work[i]);
    }
    free(numbers_work);
    printf("\n");
    printf("Riffle Numbers 5 times: \n");
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
    printf("Riffle Greek numbers :\n");
    riffle_once(greek, greek_size, sizeof (greek[0]), work);
    memcpy(greek,work,(sizeof (greek[0])*greek_size));
    for (j = 0; j < greek_size; ++j) {
        printf(" %s |",greek[j]);
    }
    printf("\n");
    free(work);
    printf("Riffle Greek 5 times: \n");
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
     */
    int i;
    int j;
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                     12, 13, 14, 15, 16, 17, 18, 19, 20};
    int numbers_size = sizeof(numbers) / sizeof (numbers[0]);
    int *numbers_work = (int *)malloc(numbers_size * sizeof (int ));
    printf("Riffle once Numbers: \n");
    riffle_once(numbers, numbers_size, sizeof (int), numbers_work);
    for (i = 0; i < numbers_size; ++i) {
        printf(" %d |",numbers_work[i]);
    }
    free(numbers_work);
    printf("\n");
    printf("Riffle Numbers 5 times: \n");
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
    printf("Riffle Greek numbers :\n");
    riffle_once(greek, greek_size, sizeof (greek[0]), work);
    memcpy(greek,work,(sizeof (greek[0])*greek_size));
    for (j = 0; j < greek_size; ++j) {
        printf(" %s |",greek[j]);
    }
    printf("\n");
    free(work);
    printf("Riffle Greek 5 times: \n");
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


}
/////////////////////////////////

void riffle(void *L, int len, int size, int N){
    int i;
    void *work = malloc(len * size);
    for (i = 0; i < N; ++i) {
        riffle_once(L, len, size, work);
        memcpy(L,work,(size*len));
    }
    free(work);
}

void riffle_once(void *L, int len, int size, void *work){
    int j;
    int k;
    void *deck1_start = L + (size*(len/2));
    void *deck2_start = L + (size*(len-1));
    void *deck1_end = L;
    void *deck2_end = deck1_start + size;
    int random;
    srand(time(0));
    //printf("d1 = %p d1end %p\n",deck1_start,deck1_end);
    //printf("d2 = %p d2end %p\n",deck2_start,deck2_end);
    for (j = 0; j < len; ++j) {
        random = rand() % 2;
        if(random == 0){
            //Take from deck 1
            if (deck1_start == deck1_end){
                // if deck 1 is almost empty e.i one left then we add the rest of deck 2 and break
                memcpy(work, deck1_start, size);
                work+=size;
                for (k = 0; k < len-j; ++k) {
                    memcpy(work, deck2_start, size);
                    deck2_start-=size;
                    work+=size;
                }
                break;
            }else{
                // deck 1 not almost empty
                memcpy(work, deck1_start, size);
            }

            deck1_start-=size;
        } else{
            if (deck2_start == deck2_end){
                // if deck 2 is almost empty e.i one left then we add the rest of deck 1 and break
                memcpy(work, deck2_start, size);
                work+=size;
                for (k = 0; k < len-j; ++k) {
                    memcpy(work, deck1_start, size);
                    deck1_start-=size;
                    work+=size;
                }
                break;
            }else{
                // deck 2 not almost empty
                memcpy(work, deck2_start, size);
            }
            deck2_start-=size;
        }
        work+=size;
    }
}

/////////////////////////////////

int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)){
    int i;
    void *first;
    void *second;
    void *copy_L = malloc(len * size); // This is the copy of L before shuffle
    memcpy(copy_L,L,(size*len));
    riffle(L,len,size,1); // Shuffle the pack

    // Checking if all items in the original are in the shuffled array
    void *copy_of_shuffle = malloc(len * size);
    memcpy(copy_of_shuffle, L, (size*len));
    qsort(copy_of_shuffle, len, size, (int (*)(const void *, const void *)) cmp);

    void *copy_L_sort = malloc(len * size);
    memcpy(copy_L_sort, copy_L, (size*len));
    qsort(copy_L_sort, len, size, (int (*)(const void *, const void *)) cmp);

    if((arrays_equal(copy_L_sort,copy_of_shuffle,len,size,cmp))!=1){ // if they are not equal
        free(copy_of_shuffle);
        free(copy_L_sort);
        free(copy_L);
        return 0;
    } else{
        free(copy_of_shuffle);
        free(copy_L_sort);
    }

    // Check that at least one of the items has been moved to a new place.
    // and that a shuffle has actually occurred
    for (i = 0; i< len; i++) {
        first = L + (i*size);
        second = copy_L + (i*size);
        if(cmp(first,second)!=0){
            free(copy_L);
            return 1; // Follows rules
        }
    }
    free(copy_L);
    return 0; // Does not follow rules
}

int arrays_equal(void *copy_of_shuffle, void *copy_L_sort, int len, int size, int (*cmp)(void *, void *)){
    int i;
    void *first;
    void *second;
    for (i = 0; i< len; i++) {
        first = copy_of_shuffle + (i*size);
        second = copy_L_sort + (i*size);
        if(cmp(first,second)!=0){
            return 0; // they are not equal
        }
    }
    return 1; // they are equal
}

int cmp_string(void *one, void *two){
    char *one_string = *((char **)one);
    char *two_string = *((char **)two);
    //printf("%s  vs %s \n",one_string, two_string);
    if(strcmp(one_string,two_string)==0){
        return 0; // the two strings are equal to each other
    }else{
        if(strcmp(one_string,two_string)>0){
            return -1; // one is greater than two
        } else{
            return 1; // two is greater than one
        }
    }
}

int cmp_integer(void *one, void *two){
    int one_int = *((int*) one);
    int two_int = *((int*) two);
    if(one_int==two_int){
        return 0;
    }else{
        if(one_int>two_int){
            return -1;
        } else{
            return 1;
        }
    }
}

/////////////////////////////////

float quality(int *numbers, int len){
    float greater_count = 0;
    float numbers_quality;
    int i;
    int current;
    int next;
    for (i = 0; i < len; ++i) {
        current = numbers[i];
        next = numbers[i+1];
        if(next>current){
            greater_count+=1;
        }
    }
    numbers_quality = (float)(greater_count/(len-1));
    return numbers_quality;
}

float average_quality(int N, int shuffles, int trials){
    float numbers_average_quality = 0;
    float quality_check;
    int i;
    int j;
    int *numbers = (int *)malloc(N*sizeof(int));
    for(i = 0; i<N; i++)
    {
        numbers[i] = i;
    }
    for (j = 0; j < trials; ++j) {
        riffle(numbers,N,sizeof (int),shuffles);
        for (i = 0; i < N; ++i) {
            printf("%d ",numbers[i]);
        }
        printf("\n");
        quality_check = quality(numbers,N);
        numbers_average_quality += quality_check;
    }
    numbers_average_quality = numbers_average_quality/(float)(trials);
    free(numbers);
    return numbers_average_quality;
}

/////////////////////////////////




