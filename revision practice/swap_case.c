// Function to print out a string that has had it's cases swapped.
// swap_case.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
 
#include <stdio.h>

int swap_case(int character);

int main(void) {

    // TODO: Write this function, using the swap_case function.
    char character;
    character = getchar();
    while (character != EOF) {
        putchar(swap_case(character));
        character = getchar();
    }

    return 0;
}

int swap_case(int character) {
    // TODO: Write this function, which should:
    //  - return character in lower case if it is an upper case letter
    //  - return character in upper case if it is an lower case letter
    //  - return the character unchanged otherwise
    if (character >= 'A' && character <= 'Z') {
        character = character + ('a' - 'A');
    } else if (character >= 'a' && character <= 'z') {
        character = character + ('A' - 'a');
    }

    return character;
}
