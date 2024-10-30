#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void) {
    char c[MAX];
    int p;
    
    while (fgets(c, MAX, stdin) != NULL) {
        // Remove the newline character if it exists
        int len = strlen(c);
        if (c[len - 1] == '\n') {
            c[len - 1] = '\0';
            len--;  // Update length after removing newline
        }
        
        // Print the characters in reverse order
        for (p = len - 1; p >= 0; p--) {
            putchar(c[p]);
        }
        putchar('\n');  // Add a newline after reversing the line
    }
        
    return 0;
}
