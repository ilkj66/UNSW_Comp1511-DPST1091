// YIMING HE z5528914
// 22/2/2024


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char *sentence = malloc(128 * sizeof(char));
    char *sentence_compare = malloc(128 * sizeof(char));
    
    printf("Enter the search term: ");
    fgets(sentence_compare, 128, stdin);

    printf("Enter the list of strings:\n");

    int occurrence_count = 0;

    // Read the first string outside the loop to avoid the uninitialized warning
    if (fgets(sentence, 128, stdin) != NULL) {
        while (1) {
            if (strcmp(sentence, sentence_compare) == 0) {
                occurrence_count++;
            } 
            
            if (fgets(sentence, 128, stdin) == NULL) {
                break;
            }
        }
    }

    printf("There was %d occurrence(s) of the search term in the input.\n"
    , occurrence_count);

    free(sentence);
    free(sentence_compare);
    return 0;
}