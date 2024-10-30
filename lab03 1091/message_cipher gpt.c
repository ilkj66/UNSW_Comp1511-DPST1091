// z5528914
#include <stdio.h>

struct message {
    char letter1;
    char letter2;
    char letter3;
    char letter4;
};

void encipher(struct message *msg, int *numbers) {
    if ((msg->letter1 >= 'A' && msg->letter1 <= 'Z') || (msg->letter1 >= 'a' && msg->letter1 <= 'z')) {
        msg->letter1 = (msg->letter1 + numbers[0] - 'A') % 26 + 'A';
    }
    if ((msg->letter2 >= 'A' && msg->letter2 <= 'Z') || (msg->letter2 >= 'a' && msg->letter2 <= 'z')) {
        msg->letter2 = (msg->letter2 + numbers[1] - 'A') % 26 + 'A';
    }
    if ((msg->letter3 >= 'A' && msg->letter3 <= 'Z') || (msg->letter3 >= 'a' && msg->letter3 <= 'z')) {
        msg->letter3 = (msg->letter3 + numbers[2] - 'A') % 26 + 'A';
    }
    if ((msg->letter4 >= 'A' && msg->letter4 <= 'Z') || (msg->letter4 >= 'a' && msg->letter4 <= 'z')) {
        msg->letter4 = (msg->letter4 + numbers[3] - 'A') % 26 + 'A';
    }
}

void decipher(struct message *msg, int *numbers) {
    if ((msg->letter1 >= 'A' && msg->letter1 <= 'Z') || (msg->letter1 >= 'a' && msg->letter1 <= 'z')) {
        msg->letter1 = (msg->letter1 - numbers[0] + 'A' + 26) % 26 + 'A';
    }
    if ((msg->letter2 >= 'A' && msg->letter2 <= 'Z') || (msg->letter2 >= 'a' && msg->letter2 <= 'z')) {
        msg->letter2 = (msg->letter2 - numbers[1] + 'A' + 26) % 26 + 'A';
    }
    if ((msg->letter3 >= 'A' && msg->letter3 <= 'Z') || (msg->letter3 >= 'a' && msg->letter3 <= 'z')) {
        msg->letter3 = (msg->letter3 - numbers[2] + 'A' + 26) % 26 + 'A';
    }
    if ((msg->letter4 >= 'A' && msg->letter4 <= 'Z') || (msg->letter4 >= 'a' && msg->letter4 <= 'z')) {
        msg->letter4 = (msg->letter4 - numbers[3] + 'A' + 26) % 26 + 'A';
    }
}

int main(void) {
    struct message msg;
    char choice;

    // Scan message into `msg` struct
    printf("Message: ");
    scanf("%c%c%c%c", &msg.letter1, &msg.letter2, &msg.letter3, &msg.letter4);

    int num1, num2, num3, num4;
    printf("Would you like to encipher or decipher this message (e/d)? ");
    scanf(" %c", &choice);

    printf("Enter numbers to %s: ", (choice == 'e') ? "encipher by" : "decipher by");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    if (choice == 'e') {
        encipher(&msg, (int[]){num1, num2, num3, num4});
    } else if (choice == 'd') {
        decipher(&msg, (int[]){num1, num2, num3, num4});
    }

    printf("%c%c%c%c", msg.letter1, msg.letter2, msg.letter3, msg.letter4);

    return 0;
}
