// z5528914

#include <stdio.h>

// This main function scans a message then enciphers it by some given inputs
int main(void) {
    // Have a think about how we might implement this with a `struct message`
    // once we've covered structs in the Thursday lecture!
    char letter1;
    char letter2;
    char letter3;
    char letter4;
    int num1, num2, num3, num4;
    // Scan message into the four characters
    printf("Message: ");
    scanf("%c%c%c%c\n", &letter1, &letter2, &letter3, &letter4);
    printf("Enter numbers to encipher by: ");
    scanf(" %d %d %d %d", &num1, &num2, &num3, &num4);
    if ((letter1 >= 'A' && letter1 <= 'Z') || (letter1 >= 'a' && letter1 <= 'z')) {
        if (num1 < -26) {
            num1 = num1 % 26 + 26;
            if (letter1 + num1 < 'a') {
                num1 = num1 + 26;
            } else {
                num1 = num1 + 0;
            }
        } else if (num1 > 26) {
            num1 = num1 % 26;
        } else if (num1 < 0 && num1 >= -26) {
            if (num1 + letter1 > 'z') {
                num1 = num1 - 26; 
            }
            if (letter1 + num1 < 'a') {
                num1 = num1 + 26;
            } else {
                num1 = num1 + 0;
            }
        } 
    }
    if ((letter2 >= 'A' && letter2 <= 'Z') || (letter2 >= 'a' && letter2 <= 'z')) {
        if (num2 < -26) {
            num2 = num2 % 26 + 26;
            if (letter2 + num2 < 'a') {
                num2 = num2 + 26;
            } else {
                num2 = num2 + 0;
            }
        } else if (num2 > 26) {
            num2 = num2 % 26;
        } else if (num2 < 0 && num2 >= -26) {
            if (num2 + letter2 > 'z') {
                num2 = num2 - 26; 
            }
            if (letter2 + num2 < 'a') {
                num2 = num2 + 26;
            } else {
                num2 = num2 + 0;
            }
        } 
    }
    if ((letter3 >= 'A' && letter3 <= 'Z') || (letter3 >= 'a' && letter3 <= 'z')) {
        if (num3 < -26) {
            num3 = num3 % 26 + 26;
            if (letter3 + num3 < 'a') {
                num3 = num3 + 26;
            } else {
                num3 = num3 + 0;
            }
        } else if (num3 > 26) {
            num3 = num3 % 26;
        } else if (num3 < 0 && num3 >= -26) {
            if (num3 + letter3 > 'z') {
                num3 = num3 - 26; 
            }
            if (letter3 + num3 < 'a') {
                num3 = num3 + 26;
            } else {
                num3 = num3 + 0;
            }
        } 
    }
    if ((letter4 >= 'A' && letter4 <= 'Z') || (letter4 >= 'a' && letter4 <= 'z')) {
        if (num4 < -26) {
            num4 = num4 % 26 + 26;
            if (letter4 + num4 < 'a') {
                num4 = num4 + 26;
            } else {
                num4 = num4 + 0;
            }
        } else if (num4 > 26) {
            num4 = num4 % 26;
            if (num4 + letter4 > 'z') {
                num4 = num4 - 26; 
            }
        } else if (num4 < 0 && num4 >= -26) {
            if (letter4 + num4 < 'a') {
                num4 = num4 + 26;
            } else {
                num4 = num4 + 0;
            }
        } 
    }
    letter1 = letter1 + num1;
    letter2 = letter2 + num2;
    letter3 = letter3 + num3;
    letter4 = letter4 + num4;
    
    printf("%c%c%c%c\n", letter1, letter2, letter3, letter4);
    return 0;

    // TODO: Encipher the letters
}

