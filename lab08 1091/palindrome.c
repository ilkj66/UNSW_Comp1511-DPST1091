// YIMING HE 
// zID: z5528914

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 4096

int main() {
    char str[4096];
    char str_dec[4096];
    printf("Enter a string: ");
    fgets (str, sizeof(str), stdin);   
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        int p = length - i - 1;
        str_dec[i] = str[p];
    }
    str_dec[length] = '\0';
    int count = 0;
    for (int k = 0; k < length && str[k] != '\0' 
    && str_dec[k] != '\0'; k++) {
        if (str[k] != str_dec[k]) {
            count++;
        }
    }
    if (count == 0) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    return 0;
}