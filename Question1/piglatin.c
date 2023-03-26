#include "piglatin.h"

/**
 * The code in main prompts the user for a sentence to convert to pig latin and will then output the converted version
 * in the console.
 * @return If it was successful executing
 */
int main(){
    char sentence[100000];
    const char s[2] = " ";
    // User inputs the sentence
    while(1) {  // Loop indefinitely until user breaks out
        printf("Enter your sentence: ");
        if (!fgets(sentence, sizeof(sentence), stdin)) {
            break; // Break out of loop if input is empty
        }
        if (sentence[0] == '\n') {
            break;
        }
        char *word = strtok(sentence, s); // Get the nth word from the sentence
        // While there is a word present convert to pig latin
        while(word!=NULL){
            // If the word is a null, \n or isn't present break
            if(strcmp(word,"\n")==0 || strlen(word)==0 || word == NULL){
                break;
            }
            else{
                // Convert the word to pig latin
                char *test1_r = pig(word);
                printf("%s ",test1_r);
                free(test1_r); // Free the word
            }
            // Get the next word
            word = strtok(NULL, s);
        }
        printf("\n");
    }
    return 0;
}