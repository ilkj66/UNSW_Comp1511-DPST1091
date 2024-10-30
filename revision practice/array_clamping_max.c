#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void clamp_max(int arr[SIZE][SIZE], int size, int max);
void print_array(int arr[SIZE][SIZE], int size);

int main(void) {

    int array1[SIZE][SIZE] = {{9, 3, 2, 5, 2},
                            {2, 12, 5, 1, 11},
                            {4, 4, 7, 7, 6},
                            {10, 0, 4, 15, 0},
                            {2, 9, 0, 4, 0}};

    printf("Before:\n");
    print_array(array1, SIZE);

    clamp_max(array1, SIZE, 10);

    printf("\nAfter:\n");
    print_array(array1, SIZE);

    return 0;
}

void print_array(int arr[SIZE][SIZE], int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%3d ", arr[row][col]);
        }
        printf("\n");
    }
}


void clamp_max(int arr[SIZE][SIZE], int size, int max) {
    // TODO: Make sure all values are <= max
    // Change any values that are > max
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (arr[i][k] > max) {
                arr[i][k] = max;
            }
        }
    }
    return;
}

