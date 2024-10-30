#include <stdio.h>

int main(void) {
    char ch;
    
    // Read characters until end of input
    while ((ch = getchar()) != EOF) {
        // Check if the character is a digit, space, or newline
        if ((ch >= '0' && ch <= '9') || ch == ' ' || ch == '\n') {
            // Write the character unchanged
            putchar(ch);
        } else {
            // Replace all other characters with '.'
            putchar('.');
        }
    }

    return 0;
}