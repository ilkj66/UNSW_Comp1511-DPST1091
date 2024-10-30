// diagonal.c
//
// Given a 2D array, this programs calculates the sum of elements on a diagonal
// i.e top left to bottom right 
//
// Written by YIMING HE z5528914
// 13/2/2024

#include <stdio.h>

#define ARRAY_MAX_SIZE 100

int diagonal_sum(int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int size);

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
int main(void) {

    int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
    int size;

    printf("Please enter the size of your square array: ");
    scanf("%d", &size);

    // scans numbers into the array
    printf("Please enter the values for your array: ");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("The sum of the diagonal is %d\n", diagonal_sum(array, size));

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

int diagonal_sum(int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int size) {

    // write your code here
    int row = 0;
    int col = 0;
    int sum = 0;
    while (row < size && col < size) {
        sum = sum + array[row][col];
        row++;
        col++;
    }
    return sum;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
