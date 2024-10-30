// z5528914
#include <stdio.h>

void delete (char word);

int main(void) {
    char word;
    while (scanf("%c", &word) != EOF) {

        delete(word);
    }   
    return 0;
}
void delete (char word) {
    if (word != 'a' && word != 'e' && word != 'i' && word != 'o' && word != 'u') {
        printf("%c", word);
    } 
    
}