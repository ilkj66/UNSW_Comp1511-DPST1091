// z5528914

#include <stdio.h>

int main(void) {
    int num;
    int num0 = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    if (num > 0) {
        while (num0 <= num) {
            printf("%d\n", num0);
            num0++;
        }
    } else if (num < 0) {
        while (num0 >= num) {
            printf("%d\n", num0);
            num0--;
        }
    } else if (num == 0) {
        printf("0");
    }
    return 0;
}