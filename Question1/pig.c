#include "pig_header.h"

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