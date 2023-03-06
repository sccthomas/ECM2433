#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char *pig(char *word);
int test_pig();
void piglatin();

int main(){
    test_pig();
    //piglatin();
    return 0;
}

void piglatin(){
    char sentence[100000];
    const char s[2] = " ";
    printf("Enter your sentence: ");
    while(scanf("%[^\n]s",sentence)){
        char *word = strtok(sentence, s);
        while(word!=NULL){
            if(strcmp(word,"\n")==0 || strlen(word)==0 || word == NULL){
                break;
            }
            else{
                char *test1_r = pig(word);
                printf("%s ",test1_r);
                free(test1_r);
            }
            word = strtok(NULL, s);
        }
        printf("\n");
    }
    }

int test_pig() {
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

char *pig(char *word){
    int strLen = strlen(word);
    char start[strLen];
    char *copy = malloc(sizeof(char) * (strlen(word)+10));
    char *end;
    int i = 0;
    int j;
    int k;
    for (k = 0; k < strLen; ++k) {
        word[k] = tolower(word[k]);
    }
    if (word[0] =='y'){
        end = "ay";
        word++;
        start[0] = 'y';
        strcat(copy,word);
        strcat(copy,start);
        strcat(copy,end);
        return copy;
    }
    if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'){
        end = "way";
        strcat(copy,word);
        strcat(copy,end);
        return copy;
    }else {
        while (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' && word[i] != '\0' && word[i] != ' '){
            if(word[i] == 'y'){
                break;
            }
            start[i] = word[i];
            i++;
        }
        end = "ay";
        for (j = 0; j < i; ++j) {
            word++;
        }
        strcat(copy,word);
        strcat(copy,start);
        strcat(copy,end);
        return copy;
    }
}