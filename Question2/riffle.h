#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void riffle_once(void *L, int len, int size, void *work);
void riffle(void *L, int len, int size, int N);
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *));
int cmp_string(void *one, void *two);
int cmp_integer(void *one, void *two);
float quality(int *numbers, int len);
float average_quality(int N, int shuffles, int trials);
int quality_c();
int arrays_equal(void *L, void *cL, int len, int size, int (*cmp)(void *, void *));



