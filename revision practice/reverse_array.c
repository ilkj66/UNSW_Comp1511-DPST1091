#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int array[MAX_SIZE];
    int i = 0;
    printf("Enter numbers forwards:\n");
    while (scanf("%d", &array[i]) != EOF) {
        i++;
    }
    printf("Reversed:\n");
    i = i - 1;
    while (i >= 0) {
        printf("%d\n", array[i]);
        i--;
    }
    return 0;
}