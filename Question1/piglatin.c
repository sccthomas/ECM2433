#include "piglatin.h"

int main(){
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
    return 0;
}