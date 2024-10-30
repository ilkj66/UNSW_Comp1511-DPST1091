// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE

#include <stdio.h>

#define SIZE 7

int find_treasure(char map[SIZE][SIZE], int *row_pointer, int *col_pointer);

// This is a simple main function that you can use to test your function.
// It will not be marked - only your function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your function directly.
// Any changes that you make to this main function will not affect the autotests.
int main(void) {

    //Feel free to modify the treasure map to test your code:
    char treasure_map[SIZE][SIZE] = {
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    };

    int row;
    int col;

    //Pass in the address of the row and column variables
    int contains_treasure = find_treasure(treasure_map, &row, &col);

    if (contains_treasure) {
        printf("Treasure was found at coordinates (%d, %d)!\n", row, col);
    } else {
        printf("The map contained no treasure :(\n");
    }
   
    return 0;
}



// Finds the location of the 'X' in the 2d array.
//
// Parameters:
//  `map`: a 2d array of chars which contains at most one 'X'.
//  `row_pointer`: A pointer to an integer. 
//      If the map contains an 'X', this pointer should be used to set the 
//      integer to the row number of the 'X'.
//  `col_pointer`: A pointer to an integer. 
//      If the map contains an 'X', this pointer should be used to set the 
//      integer to the column number of the 'X'.
//
// Returns: 1 if the treasure was found, 0 otherwise
int find_treasure(char map[SIZE][SIZE], int *row_pointer, int *col_pointer) {
    // TODO: Complete this function
    int rowf, colf;
    for (rowf = 0; rowf < SIZE; rowf++) {
        for (colf = 0; colf < SIZE; colf++) {
            if (map[rowf][colf] == 'X') {
                *row_pointer = rowf;
                *col_pointer = colf;
                return 1;
            }
        }
    }
    return 0;
}
