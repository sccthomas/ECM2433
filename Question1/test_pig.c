#include "test_pig_header.h"

int main() {
    char test1[30] = "happy";
    char *test1_r = pig(test1);
    printf("%s => %s \n", test1, test1_r);
    free(test1_r);

    char test2[30] = "duck";
    char *test2_r = pig(test2);
    printf("%s => %s \n", test2, test2_r);
    free(test2_r);

    char test3[30] = "glove";
    char *test3_r = pig(test3);
    printf("%s => %s \n", test3, test3_r);
    free(test3_r);

    char test4[30] = "evil";
    char *test4_r = pig(test4);
    printf("%s => %s \n", test4, test4_r);
    free(test4_r);

    char test5[30] = "eight";
    char *test5_r = pig(test5);
    printf("%s => %s \n", test5, test5_r);
    free(test5_r);

    char test6[30] = "yowler";
    char *test6_r = pig(test6);
    printf("%s => %s \n", test6, test6_r);
    free(test6_r);

    char test7[30] = "crystal";
    char *test7_r = pig(test7);
    printf("%s => %s \n", test7, test7_r);
    free(test7_r);
    return 0;
}