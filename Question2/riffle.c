#include "riffle.h"


int main(){
    /*
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    int *work = (int*)malloc(pack_size * sizeof (int ));

    riffle_once(numbers, pack_size, sizeof (int), work);
    int i;
    for (i = 0; i < pack_size; ++i) {
        printf("%d \n",work[i]);
    }
    free(work);
    */


    /*
    //int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta",
                     "eta", "theta", "iota", "kappa", "lambda", "mu" };
    int pack_size = sizeof(greek) / sizeof (greek[0]);
    riffle(greek,pack_size,sizeof (greek[0]),5);
    int i;
    for (i = 0; i < pack_size; ++i) {
        printf("%s \n",greek[i]);
    }
    */


    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon",
                     "zeta", "eta", "theta", "iota", "kappa", "lambda", "mu" };
    int pack_size = sizeof(greek) / sizeof (greek[0]);
    int good = check_shuffle(greek,pack_size,sizeof (greek[0]),cmp_string);
    printf("%d \n",good);
    return 1;



    /*
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int pack_size = sizeof(numbers) / sizeof (numbers[0]);
    int good = check_shuffle(numbers,pack_size,sizeof (numbers[0]),cmp_integer);
    printf("%d",good);
    return 1;
     */

}

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
    int i;
    int j;
    int k;
    void *deck1_start;
    void *deck2_start;
    void *deck1_end = L;
    void *deck2_end;
    int random;
    srand(time(0));

    for (i = 0; i < len/2-1; ++i) {
        L+=size;
    }
    deck1_start = L;
    L+=size;
    deck2_end = L;
    L-=size;
    for (i = 0; i < len/2; ++i) {
        L+=size;
    }
    deck2_start = L;
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

    /*
    printf(" initial %p \n",L);
    printf(" initial %p \n",work);
    work = L;
    L++;
    printf(" increment %p \n",L);
    printf(" set work to L[0] %p \n",work);
    work = L;
    L++;
    printf(" increment %p \n",L);
    printf(" set work to L[1] %p \n",work);
    work--;
    printf(" set work to L[0] %p \n",work);


    printf(" 1 %p \n",L);
    L++;
    printf(" 2 %p \n",L);
    L--;
    printf(" 2 %p \n",L);
 */



}



int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)){
    // Call riffle and then make a copy of the previous L and then compare the two things.
    // We need 2 or 3 functions to compare int to int and string to string, maybe char to char.
    // The cmp is a function pointer to the compare function.
    int i;
    void *first;
    void *second;
    void *copy_L = malloc(len * size); // This is the copy of L
    memcpy(copy_L,L,(size*len));

    riffle(L,len,size,1);
    for (i = 0; i< len; i++) {
        first = L + (i*size);
        second = copy_L + (i*size);
        if(cmp(first,second)==1){
            free(copy_L);
            return 0;
        }
    }
    free(copy_L);
    return 1;
}

int cmp_string(void *one, void *two){
    char *one_string = *((char **)one);
    char *two_string = *((char **)two);
    printf("%s  vs %s \n",one_string, two_string);
    if(strcmp(one_string,two_string)==0){
        return 1;
    }else{
        return 0;
    }
}

int cmp_integer(void *one, void *two){
    int one_int = *((int*) one);
    int two_int = *((int*) two);
    printf("%d  vs %d \n",one_int, two_int);
    if(one_int==two_int){
        return 1;
    }else{
        return 0;
    }
}
