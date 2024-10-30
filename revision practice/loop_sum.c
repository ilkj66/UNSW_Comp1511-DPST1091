#include <stdio.h>

int main(void) {
    int num;
    int sum = 0;
    printf("How many numbers: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        int value;
        scanf("%d", &value);
        sum = sum + value;
    }
    printf("The sum is: %d\n", sum);
    return 0;
}