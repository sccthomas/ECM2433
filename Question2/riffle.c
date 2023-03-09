#include "riffle.h"

/////////////////////////////////

void riffle(void *L, int len, int size, int N){
    int i;
    void *work = malloc(len * size);
    for (i = 0; i < N; ++i) {
        riffle_once(L, len, size, work);
    }
    free(work);
}

void riffle_once(void *L, int len, int size, void *work){
    int j;
    int k;
    void *work_start = work;
    void *deck1_start = L;
    void *deck1_end = L + (size*(len/2));
    void *deck2_start = deck1_end + size;
    void *deck2_end = L + (size*(len-1));
    int random;
    srand(time(0));
    //printf("d1 = %p d1end %p\n",deck1_start,deck1_end);
    //printf("d2 = %p d2end %p\n",deck2_start,deck2_end);
    for (j = 0; j < len; ++j) {
        random = rand() % 2;
        if(random == 0) {
            if (deck1_start!=deck1_end){
                memcpy(work,deck1_start,size);
                deck1_start+=size;
            } else{
                memcpy(work,deck1_start,size);
                work+=size;
                while (deck2_start!=deck2_end){
                    memcpy(work,deck2_start,size);
                    deck2_start+=size;
                    work+=size;
                }
                memcpy(work,deck2_start,size);
                break;
            }
        }else{
            if (deck2_start!=deck2_end){
                memcpy(work,deck2_start,size);
                deck2_start+=size;
            } else{
                memcpy(work,deck2_start,size);
                work+=size;
                while (deck1_start!=deck1_end){
                    memcpy(work,deck1_start,size);
                    deck1_start+=size;
                    work+=size;
                }
                memcpy(work,deck1_start,size);
                break;
            }
        }
        work+=size;
    }
    int i;
    for (i = 0; i < len; ++i) {
        memcpy(L+(i*size),work_start+(i*size),size);
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
    float average_quality_ = 0;
    int i;
    int j;
    int numbers_[N];
    for (i = 0;  i< trials; i++) {
        for (j = 0; j < N; ++j) {
            numbers_[j] = j;
        }
        riffle(numbers_,N,4,shuffles);
        average_quality_ += quality(numbers_,N);
    }
    return average_quality_/trials;
}

/////////////////////////////////




