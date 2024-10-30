#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("Please enter a size: ");
    scanf("%d", &n);

    // Top half of the hourglass
    i = 0;
    while (i < n / 2 + 1) {
        j = 0;
        while (j < i) {
            printf("-");
            j++;
        }
        j = 0;
        while (j < n - 2 * i) {
            printf("*");
            j++;
        }
        j = 0;
        while (j < i) {
            printf("-");
            j++;
        }
        printf("\n");
        i++;
    }

    // Bottom half of the hourglass
    i = n / 2 - 1;
    while (i >= 0) {
        j = 0;
        while (j < i) {
            printf("-");
            j++;
        }
        j = 0;
        while (j < n - 2 * i) {
            printf("*");
            j++;
        }
        j = 0;
        while (j < i) {
            printf("-");
            j++;
        }
        printf("\n");
        i--;
    }

    return 0;
}
