#include <stdio.h>
#include <ctype.h>
struct message {
    char letter1;
    char letter2;
    char letter3;
    char letter4;
};

int main(void) {
    struct message msg;
    
    // Scan message into `msg` struct
    printf("Message: ");
    scanf("%c%c%c%c",&msg.letter1, &msg.letter2, &msg.letter3, &msg.letter4);
// You can continue from here
    int num1, num2, num3, num4;
    char choice;
    printf("Would you like to encipher or decipher this message (e/d)? ");
    scanf(" %c", &choice);
    printf("\nEnter numbers to encipher by:");
    scanf(" %d %d %d %d", &num1, &num2, &num3, &num4);
    
    
    if (choice == 'e') {
        if ((msg.letter1 >= 'A' && msg.letter1 <= 'Z') || (msg.letter1 >= 'a' && msg.letter1 <= 'z')) {
        if (num1 < -26) {
            num1 = num1 % 26 + 26;
            if (msg.letter1 + num1 < 'a') {
                num1 = num1 + 26;
            } else {
                num1 = num1 + 0;
            }
        } else if (num1 > 26) {
            num1 = num1 % 26;
        } else if (num1 < 0 && num1 >= -26) {
            if (num1 + msg.letter1 > 'z') {
                num1 = num1 - 26; 
            }
            if (msg.letter1 + num1 < 'a') {
                num1 = num1 + 26;
            } else {
                num1 = num1 + 0;
            }
        }
    }
    if ((msg.letter2 >= 'A' && msg.letter2 <= 'Z') || (msg.letter2 >= 'a' && msg.letter2 <= 'z')) {
        if (num2 < -26) {
            num2 = num2 % 26 + 26;
            if (msg.letter2 + num2 < 'a') {
                num2 = num2 + 26;
            } else {
                num2 = num2 + 0;
            }
        } else if (num2 > 26) {
            num2 = num2 % 26;
        } else if (num2 < 0 && num2 >= -26) {
            if (num2 + msg.letter2 > 'z') {
                num2 = num2 - 26; 
            }
            if (msg.letter2 + num2 < 'a') {
                num2 = num2 + 26;
            } else {
                num2 = num2 + 0;
            }
        } 
    }
    if ((msg.letter3 >= 'A' && msg.letter3 <= 'Z') || (msg.letter3 >= 'a' && msg.letter3 <= 'z')) {
        if (num3 < -26) {
            num3 = num3 % 26 + 26;
            if (msg.letter3 + num3 < 'a') {
                num3 = num3 + 26;
            } else {
                num3 = num3 + 0;
            }
        } else if (num3 > 26) {
            num3 = num3 % 26;
        } else if (num3 < 0 && num3 >= -26) {
            if (num3 + msg.letter3 > 'z') {
                num3 = num3 - 26; 
            }
            if (msg.letter3 + num3 < 'a') {
                num3 = num3 + 26;
            } else {
                num3 = num3 + 0;
            }
        } 
    }
    if ((msg.letter4 >= 'A' && msg.letter4 <= 'Z') || (msg.letter4 >= 'a' && msg.letter4 <= 'z')) {
        if (num4 < -26) {
            num4 = num4 % 26 + 26;
            if (msg.letter4 + num4 < 'a') {
                num4 = num4 + 26;
            } else {
                num4 = num4 + 0;
            }
        } else if (num4 > 26) {
            num4 = num4 % 26;
            if (num4 + msg.letter4 > 'z') {
                num4 = num4 - 26; 
            }
        } else if (num4 < 0 && num4 >= -26) {
            if (msg.letter4 + num4 < 'a') {
                num4 = num4 + 26;
            } else {
                num4 = num4 + 0;
            }
        } 
        }
        msg.letter1 = msg.letter1 + num1;
        msg.letter2 = msg.letter2 + num2;
        msg.letter3 = msg.letter3 + num3;
        msg.letter4 = msg.letter4 + num4;
    }
    if (choice == 'd') {
        if ((msg.letter1 >= 'A' && msg.letter1 <= 'Z') || (msg.letter1 >= 'a' && msg.letter1 <= 'z')) {
            if (num1 < -26) {
                num1 = num1 % -26;
                if (num1 + msg.letter1 < 'a'|| num1 + msg.letter1 < 'A') {
                    num1 = num1 + 26;
                } else {
                    num1 = 0 + num1;
                }
            } else if (num1 >= -26 && num1 <= 0) {
                if (num1 + msg.letter1 < 'a'|| num1 + msg.letter1 < 'A') {
                    num1 = 26 + num1;
                } 
            } else if (num1 > 26) {
                num1 = num1 % 26;
                if (msg.letter1 - num1 < 'a' || msg.letter1 - num1 < 'A') {
                    num1 = 26 - num1;
                } else {
                    num1 = 0 - num1;
                }
            }
        }
        if ((msg.letter2 >= 'A' && msg.letter2 <= 'Z') || (msg.letter2 >= 'a' && msg.letter2 <= 'z')) {
            if (num2 < -26) {
                num2 = num2 % -26;
                if (num2 + msg.letter2 < 'a'|| num2 + msg.letter2 < 'A') {
                    num2 = num2 + 26;
                } else {
                    num2 = 0 + num2;
                }
            } else if (num2 >= -26 && num2 <= 0) {
                if (num2 + msg.letter2 < 'a'|| num2 + msg.letter2 < 'A') {
                    num2 = 0 - num2;
                } 
            } else if (num2 > 26) {
                num2 = num2 % 26;
                if (msg.letter2 - num2 < 'a' || msg.letter2 - num2 < 'A') {
                    num2 = 26 - num2;
                } else {
                    num2 = 0 - num2;
                }
            }
        }
        if ((msg.letter3 >= 'A' && msg.letter3 <= 'Z') || (msg.letter3 >= 'a' && msg.letter3 <= 'z')) {
            if (num3 < -26) {
                num3 = num3 % -26;
                if (num3 + msg.letter3 < 'a'|| num3 + msg.letter3 < 'A') {
                    num3 = num3 + 26;
                } else {
                    num3 = 0 + num3;
                }
            } else if (num3 >= -26 && num3 <= 0) {
                if (num3 + msg.letter3 < 'a'|| num3 + msg.letter3 < 'A') {
                    num3 = 0 - num3;
                } 
            } else if (num3 > 26) {
                num3 = num3 % 26;
                if (msg.letter3 - num3 < 'a' || msg.letter3 - num3 < 'A') {
                    num3 = 26 - num3;
                } else {
                    num3 = 0 - num3;
                }
            }
        }
        if ((msg.letter4 >= 'A' && msg.letter4 <= 'Z') || (msg.letter4 >= 'a' && msg.letter4 <= 'z')) {
            if (num4 < -26) {
                num4 = num4 % -26;
                if (num4 + msg.letter4 < 'a'|| num4 + msg.letter4 < 'A') {
                    num4 = num4 + 26;
                } else {
                    num4 = 0 + num4;
                }
            } else if (num4 >= -26 && num4 <= 0) {
                if (num4 + msg.letter4 < 'a'|| num4 + msg.letter4 < 'A') {
                    num4 = 0 - num4;
                } 
            } else if (num4 > 26) {
                num4 = num4 % 26;
                if (msg.letter4 - num4 < 'a' || msg.letter4 - num4 < 'A') {
                    num4 = 26 - num4;
                } else {
                    num4 = 0 - num4;
                }
            }
        }
        msg.letter1 = msg.letter1 - num1;
        msg.letter2 = msg.letter2 - num2;
        msg.letter3 = msg.letter3 - num3;
        msg.letter4 = msg.letter4 - num4;
    }
    
    
    
    printf("%c%c%c%c\n", msg.letter1, msg.letter2, msg.letter3, msg.letter4);
    return 0;
}