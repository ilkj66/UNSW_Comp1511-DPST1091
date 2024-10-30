// z5528914

#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int vowels = 0, consonants = 0;
    
    printf("Enter a sequence of characters: ");
    
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    
    return 0;
}