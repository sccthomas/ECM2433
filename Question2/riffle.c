#include "riffle.h"

/////////////////////////////////

/**
 * The function riffle will take in a void array and then riffle the array N times
 * @param L The array being shuffled
 * @param len The length of L
 * @param size The size of the elements in L
 * @param N N is the amount of times the array should be shuffled
 */
void riffle(void *L, int len, int size, int N){
    int i;
    void *work = malloc(len * size);
    // Check if the malloc was successful
    if(work == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    // start the shuffle
    for (i = 0; i < N; ++i) {
        riffle_once(L, len, size, work);
    }
    free(work);
}

/**
 * The function riffle_once will take in a void array L and then riffle the function once
 * @param L The array being riffled
 * @param len The length of the array
 * @param size The size of the elements in L
 * @param work The work array that is being used to store the new shuffled array.
 */
void riffle_once(void *L, int len, int size, void *work){
    int j;
    void *work_start = work; // The start pointer of work
    void *deck1_start = L;  // The start pointer of deck 1
    void *deck1_end = L + (size*(len/2)); // The end  pointer of deck 1
    void *deck2_start = deck1_end + size; // The start pointer of deck 2
    void *deck2_end = L + (size*(len-1)); // The end pointer of deck 2
    int random;
    for (j = 0; j < len; ++j) {
        random = rand() % 2; // The random number either 0 or 1
        if(random == 0) { // Add from deck 1
            if (deck1_start!=deck1_end){ // If there are still cards to put on work
                memcpy(work,deck1_start,size);
                deck1_start+=size;
            } else{ // Deck 1 is empty, so we then add all off deck 2 to work
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
        }else{ // Add from deck 2
            if (deck2_start!=deck2_end){ // There are still cards in the deck to add to work
                memcpy(work,deck2_start,size);
                deck2_start+=size;
            } else{ // Deck 2 is empty, so we then add all off deck 1 to work
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
    // Make the original array contain the work array only
    int i;
    for (i = 0; i < len; ++i) {
        memcpy(L+(i*size),work_start+(i*size),size);
    }
}

/////////////////////////////////

/**
 * The function check_shuffle will check if a shuffle was successful, by checking if any element is in a new position
 * and if the new shuffled array contains the original array, meaning check for data loss.
 * @param L The array being riffled
 * @param len The length of L
 * @param size The size of the elements in L
 * @param cmp The compare function pointer, for what to use when comparing each array
 * @return 1 if the shuffle meets the rules and 0 if the shuffle doesn't follow them
 */
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)){
    int i;
    void *first;
    void *second;
    void *copy_L = malloc(len * size); // This is the copy of L before shuffle
    if(copy_L == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    memcpy(copy_L,L,(size*len));
    riffle(L,len,size,1); // Shuffle the pack

    // Checking if all items in the original are in the shuffled array
    void *copy_of_shuffle = malloc(len * size);
    if(copy_of_shuffle == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    memcpy(copy_of_shuffle, L, (size*len));
    qsort(copy_of_shuffle, len, size, (int (*)(const void *, const void *)) cmp);

    void *copy_L_sort = malloc(len * size);
    if(copy_L_sort == NULL){
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    memcpy(copy_L_sort, copy_L, (size*len));
    qsort(copy_L_sort, len, size, (int (*)(const void *, const void *)) cmp);

    if((arrays_equal(copy_L_sort,copy_of_shuffle,len,size,cmp))!=1){ // if the shuffle and original array are equal
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

/**
 * This function takes in two arrays and then checks if the two arrays are the same, returning 1 if they are.
 * @param copy_of_shuffle The shuffled array
 * @param copy_L_sort The un-shuffled array
 * @param len The lengths of the two arrays
 * @param size The size of elements in the arrays
 * @param cmp The compare function being used to compare two items in the arrays
 * @return Returns 1 if they are the same and 0 if they are not
 */
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

/**
 * This function will compare two given strings
 * @param one String 1
 * @param two String 2
 * @return Returns 0 if they are equal to each other, -1 or 1 if they are not equal to each other
 */
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

/**
 * This function will compare two integers to each other and return if they are the same or not
 * @param one Integer 1
 * @param two Integer 2
 * @return Returns 0 if the same, -1 or 1 if they are not the same
 */
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

/**
 * This function will check the quality of a shuffle to see if items are not in ascending order. The return value is the
 * amount of pairs that are not in ascending order / the length of numbers
 * @param numbers The numbers that have been shuffled
 * @param len The length of numbers
 * @return Returns the quality value of the shuffle
 */
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

/**
 * The function average_quality will calculate the average quality of a trials riffles and return this. It will create
 * an array from 1 to N-1 and then riffle this array shuffle times over a loop from 0 to trials. Each time a new array
 * is made so that the numbers start again in ascending order, so as to give the most accurate results.
 * @param N The amount of elements in the array
 * @param shuffles How many times to riffle the numbers array
 * @param trials How many trials to run
 * @return The average quality over trials
 */
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




