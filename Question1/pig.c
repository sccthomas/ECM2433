#include "pig.h"

/**
 * The function pig takes in as an argument a pointer to the word being translated. It will then convert the word based
 * on a set of rules to pig latin.
 * @param word The word being translated
 * @return The pig latin version of word
 */
char *pig(char *word){
    int strLen = strlen(word); // Calculate the length of the word
    char start[strLen]; // Create an array for the first section of the final word
    char *copy = malloc(sizeof(char) * (strlen(word)+10)); // Make a copy of the inputted word
    // Check that the malloc occurred correctly
    if (copy == NULL) {
        fprintf(stderr, "Malloc Failed\n");
        fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
        exit(-1);
    }
    char *end; // The end section of the word
    int i = 0;
    int j;
    int k;
    // Convert all the letters to lower case
    for (k = 0; k < strLen; ++k) {
        word[k] = tolower(word[k]);
    }
    // If the first letter is Y then we add ay to the end
    if (word[0] =='y'){
        end = "ay";
        word++;
        start[0] = 'y';
        // Combining the sections of the final word together word+start+end
        strcat(copy,word);
        strcat(copy,start);
        strcat(copy,end);
        // Return the copy which contains the new word
        return copy;
    }
    // If the word begins with a vowel then we add a way to the end of the final word
    if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'){
        end = "way";
        // Combining the sections of the final word together word+end
        strcat(copy,word);
        strcat(copy,end);
        // Return the copy which contains the new word
        return copy;
    }else {
        // If the word does not start with a vowel but a consonant then we add ay to the end
        while (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' && word[i] != '\0' && word[i] != ' '){
            // If the word contains a Y then we break and the start is now the Y
            if(word[i] == 'y'){
                break;
            }
            start[i] = word[i];
            i++;
        }
        end = "ay";
        // Move the word pointer to the new start section of the new word
        for (j = 0; j < i; ++j) {
            word++;
        }
        // Combining the sections of the final word together word+start+end
        strcat(copy,word);
        strcat(copy,start);
        strcat(copy,end);
        // Return the copy which contains the new word
        return copy;
    }
}