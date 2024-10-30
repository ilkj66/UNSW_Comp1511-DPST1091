// YIMING HE 
// zID: z5528914

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 4096

int main() {
    
    char str[MAX_LENGTH];
    char str_cpy[MAX_LENGTH];
    char str_cg[MAX_LENGTH];
    printf("Enter a string: ");
    fgets (str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    int length = strlen(str);
    int p = 0;
    int f = 0;
    while (p < length) {
        if(ispunct(str[p])) {
            f = f + 0;
        } else {
            str_cpy[f] = str[p];
            f++;
        }
        p++;
    }
    int count = 0;
    int length_cpy = strlen(str_cpy);
    for (int e = 0; e < length_cpy; e++) {
        int i = length_cpy - e - 1;
        str_cg[i] = str_cpy[p];
    }
    for (int k = 0; k < length_cpy && str[k] != '\0'; k++) {
        if (str_cg[k] != str_cpy[k]) {
            count++;
        }
    }
    if (count == 0) {
        printf("String is a palindrome");
    } else {
        printf("String is not a palindrome");
    }
    return 0;
}