// A simpler version of the famous Snake game!
//
// Written by Rory Golledge (z5308772) on 3/3/23
// Modified by Yiming He (z5528914) on 13/2/24
//

#include <stdio.h>

#define SIZE 8

enum land {
    NOT_VISITED,
    VISITED,
    SNAKE,
    APPLE
};

void initialise_map(enum land map[SIZE][SIZE]);
void print_map(enum land map[SIZE][SIZE]);

int main(void) {
    enum land map[SIZE][SIZE];
    initialise_map(map);
 
    printf("Welcome to Snake!\n");

    // TODO: Complete the program
    int snake_row, snake_col;
    int apple_row, apple_col;
    char ctrl;
    printf("Please enter apple location: ");
    scanf("%d %d", &apple_row, &apple_col);
    map[apple_row][apple_col] = APPLE;
    printf("Please enter snake location: ");
    scanf("%d %d", &snake_row, &snake_col);
    map[snake_row][snake_col] = SNAKE;
    print_map(map);
    while (map[apple_row][apple_col] != SNAKE) {
        scanf("%c", &ctrl);
        if (ctrl == 'r') {
            map[snake_row][snake_col] = VISITED;
            snake_col = snake_col + 1;
            map[snake_row][snake_col] = SNAKE;
            print_map(map);
        } else if (ctrl == 'u') {
            map[snake_row][snake_col] = VISITED;
            snake_row = snake_row - 1;
            map[snake_row][snake_col] = SNAKE;
            print_map(map);
        } else if (ctrl == 'l') {
            map[snake_row][snake_col] = VISITED;
            snake_col = snake_col - 1; 
            map[snake_row][snake_col] = SNAKE;
            print_map(map);
        } else if (ctrl == 'd') {
            map[snake_row][snake_col] = VISITED;
            snake_row = snake_row + 1;
            map[snake_row][snake_col] = SNAKE;
            print_map(map);
        }
        if (map[apple_row][apple_col] == map[snake_row][snake_col]) {
            map[apple_row][apple_col] = SNAKE;
            printf("Chomp!\n");
        }
    }
    return 0;
}

/**
 * Initialises the given `map` such that all tiles are `NOT_VISITED`
 * 
 * Parameters:
 *     map - The map to initialise
 * 
 * Returns:
 *     Nothing
 */
void initialise_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            map[row][col] = NOT_VISITED;
        }
    }
}

/**
 * Prints the given `map` such that all enum values are printed as nice
 * characters.
 * 
 * Parameters:
 *     map - The map to print out
 * 
 * Returns:
 *     Nothing
 */
void print_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (map[row][col] == NOT_VISITED) {
                printf(". ");
            } else if (map[row][col] == VISITED) {
                printf("- ");
            } else if (map[row][col] == SNAKE) {
                printf("S ");
            } else if (map[row][col] == APPLE) {
                printf("A ");
            }
        }
        printf("\n");
    }
}