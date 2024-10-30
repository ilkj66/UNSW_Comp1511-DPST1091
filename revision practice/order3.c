#include <stdio.h>

int main(void) {
    int num1, num2, num3;
    int val1, val2, val3;
    printf("Enter integer: ");
    scanf("%d", &num1);
    printf("Enter integer: ");
    scanf("%d", &num2);
    printf("Enter integer: ");
    scanf("%d", &num3);
    if (num1 > num2) {
        if (num3 > num1) {
            val1 = num3;
            val2 = num1;
            val3 = num2;
        } else if (num3 < num2){
            val1 = num1;
            val2 = num2;
            val3 = num3;
        } else {
            val1 = num1;
            val2 = num3;
            val3 = num2;
        }
    } else {
        if (num3 > num2) {
            val1 = num3;
            val2 = num2;
            val3 = num1;
        } else if (num3 < num1) {
            val1 = num2;
            val2 = num1;
            val3 = num3;
        } else {
            val1 = num2;
            val2 = num3;
            val3 = num1;
        }
    }
    printf("The integers in order are: %d %d %d\n", val3, val2, val1);
    return 0;
}