// Program name
//
// This program was written by Yiming He (z5528914)
// on 19/2/2024
//
// TODO: Description of program

#include <math.h>
#include <stdio.h>

// Provided constants
#define NUM_ROWS 8
#define NUM_COLS 10
#define NUM_FLOORS 5

#define TRUE 1
#define FALSE 0

// TODO: put your constants here 

// Provided enums
enum entity {
    EMPTY_ENTITY,
    WALL,
    DOT,
    APPLE,
    BANANA,
    POWER_UP,
    STAIRCASE_UP,
    STAIRCASE_DOWN,
};

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Provided structs
struct enemy {
    enum direction move_direction;
    int is_present;
    // You will need to add more to this struct in stage 3
    int enemy_col;
    int enemy_row;
};

struct tile {
    enum entity entity;
    struct enemy enemy;
};

// TODO: Put your structs here 

////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your function prototypes here

////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void initialise_map(struct tile map[NUM_ROWS][NUM_COLS]);
void print_map(
    struct tile map[NUM_ROWS][NUM_COLS],
    int pacman_row,
    int pacman_col
);


int main(void) {
    struct tile map[NUM_ROWS][NUM_COLS];
    initialise_map(map);

    printf("Welcome to cs_pacman!\n");

    // TODO: Start Stage 1.1 here
    printf("Enter Pacman's starting coordinates: ");
    int pacman_row;
    int pacman_col;
    int apple_row, apple_col;
    int banana_row, banana_col;
    scanf("%d %d", &pacman_row, &pacman_col);
    print_map(map, pacman_row, pacman_col);
    printf("Create the level:\n");
    char command;
    while (1) {
        // start_row, start_col, end_row and end_col
        for(int row_dot = 0; row_dot <= 7; row_dot++) {
            for(int col_dot = 0; col_dot <= 9; col_dot++) {
                map[row_dot][col_dot].entity = DOT;
            }
        }
        while (1) {
            command = getchar();
            if (command == 'W') {
                int start_col, start_row, end_row, end_col;
                scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
                if (start_col == end_col || start_row == end_row) {
                    if (end_row > 7) {
                        end_row = 7;
                    }
                    if (end_col > 9) {
                        end_col = 9;
                    }
                    if (start_row < 0) {
                        start_row = 0;
                    }
                    if (start_col < 0) {
                        start_col = 0;
                    }
                    for (int row = start_row; row <= end_row; row++) {
                        for (int col = start_col; col <= end_col; col++) {
                            map[row][col].entity = WALL;
                        }
                    }
                } else {
                    printf("Given wall is not horizontal or vertical!\n");
                } 
            } else if (command == 'A') {
                scanf("%d %d", &apple_row, &apple_col);
                if (map[apple_row][apple_col].entity != WALL &&
                  (apple_row != pacman_row || apple_col != pacman_col)) {
                    map[apple_row][apple_col].entity = APPLE;
                }
            } else if (command == 'B') {
                scanf("%d %d", &banana_row, &banana_col);
                if (map[banana_row][banana_col].entity != WALL &&
                 (banana_row != pacman_row || banana_col != pacman_col)) {
                    map[banana_row][banana_col].entity = BANANA;
                }
            } else if (command == 'S') {
                break;
            }
        }
        break;
    }
    print_map(map, pacman_row, pacman_col);
    char move_comand;
    int pacman_col_copy = pacman_col;
    int pacman_row_copy = pacman_row;
    int point_count = 0;
    int i = 0;
    int check_point = 0;
    printf("Enter command: ");
    while ((scanf("%c", &move_comand)) != EOF) {
        if (move_comand == 'w') {
            map[pacman_row][pacman_col].entity = EMPTY_ENTITY;
            if (pacman_row == 0) {
                pacman_row = pacman_row + 7;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            } else {
                pacman_row = pacman_row - 1;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            }
            if (map[pacman_row][pacman_col].entity == WALL) {
                pacman_row = pacman_row + 1;
            }
            if (pacman_row < 0) {
                pacman_row = pacman_row + 7;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            }
            if (i == 0) {
                map[pacman_row_copy][pacman_col_copy].entity = DOT;
            }
            if (map[pacman_row][pacman_col].entity == APPLE) {
                if (pacman_col >= 2 && pacman_col <= 7) {
                    for(int col = pacman_col - 2; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                } else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }      
                            }
                            col++;
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col < 2) {
                    for(int col = 0; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col > 7) {
                    for(int col = pacman_col - 2; col <= 9; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }
                    }
                }
            } else if (map[pacman_row][pacman_col].entity == BANANA) {
                for (int col = pacman_col; col <= 9 &&
                 map[pacman_row][col].entity != WALL; col++) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int col = pacman_col; col >= 0 &&
                 map[pacman_row][col].entity != WALL; col--) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row <= 7 &&
                 map[row][pacman_col].entity != WALL; row++) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row >= 0 &&
                 map[row][pacman_col].entity != WALL; row--) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
            }
            check_point = 0;
            for (int check_col = 0; check_col <= 9; check_col++) {
                for (int check_row = 0; check_row <= 7; check_row++) {
                    if (map[check_row][check_col].entity != DOT) {
                        check_point++;
                    }
                }
            }
            i++;
            if (check_point == 79) {
                printf("Game won! You got %d points.\n", point_count);
            } else if (check_point != 79 && move_comand != 'p'){
                print_map(map, pacman_row, pacman_col);
                printf("Enter command: ");
            } 
        } else if (move_comand == 's') {
            map[pacman_row][pacman_col].entity = EMPTY_ENTITY;
            if (pacman_row == 7) {
                pacman_row = 0;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            } else {    
                pacman_row = pacman_row + 1;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            }
            if (map[pacman_row][pacman_col].entity == WALL) {
                pacman_row = pacman_row - 1;
            }
            if (pacman_row < 0) {
                pacman_row = pacman_row - 7;
                if (map[pacman_row][pacman_col].entity == DOT) {
                    point_count = point_count + 10;
                }
            }
            if (i == 0) {
                map[pacman_row_copy][pacman_col_copy].entity = DOT;
            } 
            if (map[pacman_row][pacman_col].entity == APPLE) {
                if (pacman_col >= 2 && pacman_col <= 7) {
                    for(int col = pacman_col - 2; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                
                                }      
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col < 2) {
                    for(int col = 0; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col > 7) {
                    for(int col = pacman_col - 2; col <= 9; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }
                    }
                }
            }else if (map[pacman_row][pacman_col].entity == BANANA) {
                for (int col = pacman_col; col <= 9 &&
                 map[pacman_row][col].entity != WALL; col++) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int col = pacman_col; col >= 0 &&
                 map[pacman_row][col].entity != WALL; col--) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row <= 7 &&
                 map[row][pacman_col].entity != WALL; row++) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row >= 0 &&
                 map[row][pacman_col].entity != WALL; row--) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
            }
            check_point = 0;
            for (int check_col = 0; check_col <= 9; check_col++) {
                for (int check_row = 0; check_row <= 7; check_row++) {
                    if (map[check_row][check_col].entity != DOT) {
                        check_point++;
                    }
                }
            }
            i++;
            if (check_point == 79) {
                printf("Game won! You got %d points.\n", point_count);
            } else if (check_point != 79 && move_comand != 'p'){
                print_map(map, pacman_row, pacman_col);
                printf("Enter command: ");
            } 
        } else if (move_comand == 'a') {
            map[pacman_row][pacman_col].entity = EMPTY_ENTITY;
            if (pacman_col == 0) {
                if (map[pacman_row][9].entity == WALL) {
                    pacman_col = pacman_col + 0;
                } else {
                    pacman_col = 9;
                    if (map[pacman_row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    }
                }
            } else {
                if (map[pacman_row][pacman_col - 1].entity == WALL) {
                    pacman_col = pacman_col + 0;
                } else {
                    pacman_col = pacman_col - 1;
                    if (map[pacman_row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    }
                }
            }  
            if (i == 0) {
                map[pacman_row_copy][pacman_col_copy].entity = DOT;
            }
            if (map[pacman_row][pacman_col].entity == APPLE) {
                if (pacman_col >= 2 && pacman_col <= 7) {
                    for(int col = pacman_col - 2; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                
                                }      
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col < 2) {
                    for(int col = 0; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col > 7) {
                    for(int col = pacman_col - 2; col <= 9; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }
                    }
                }
            } else if (map[pacman_row][pacman_col].entity == BANANA) {
                for (int col = pacman_col; col <= 9 &&
                 map[pacman_row][col].entity != WALL; col++) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int col = pacman_col; col >= 0 &&
                 map[pacman_row][col].entity != WALL; col--) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row <= 7 &&
                 map[row][pacman_col].entity != WALL; row++) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row >= 0 &&
                 map[row][pacman_col].entity != WALL; row--) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
            }
            check_point = 0;
            for (int check_col = 0; check_col <= 9; check_col++) {
                for (int check_row = 0; check_row <= 7; check_row++) {
                    if (map[check_row][check_col].entity != DOT) {
                        check_point++;
                    }
                }
            }
            i++;
            if (check_point == 79) {
                printf("Game won! You got %d points.\n", point_count);
            } else if (check_point != 79 && move_comand != 'p'){
                print_map(map, pacman_row, pacman_col);
                printf("Enter command: ");
            } 
        } else if (move_comand == 'd') {
            map[pacman_row][pacman_col].entity = EMPTY_ENTITY;
            if (pacman_col == 9) {
                if (map[pacman_row][0].entity == WALL) {
                    pacman_col = pacman_col + 0;
                } else {
                    pacman_col = 0;
                    if (map[pacman_row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    }
                }
            } else {
                if (map[pacman_row][pacman_col + 1].entity == WALL) {
                    pacman_col = pacman_col + 0;
                } else {
                    pacman_col = pacman_col + 1;
                    if (map[pacman_row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    }
                }
            }   
            if (i == 0) {
                map[pacman_row_copy][pacman_col_copy].entity = DOT;
            }
            if (map[pacman_row][pacman_col].entity == APPLE) {
                if (pacman_col >= 2 && pacman_col <= 7) {
                    for(int col = pacman_col - 2; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                } else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }      
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col < 2) {
                    for(int col = 0; col <= pacman_col + 2; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                }
                            }
                        }
                    }
                } else if (pacman_col > 7) {
                    for(int col = pacman_col - 2; col <= 9; col++) {
                        if (pacman_row >= 2 && pacman_row <= 5) {
                            for(int row = pacman_row - 2; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        } else if (pacman_row < 2) {
                            for(int row = 0; row <= pacman_row + 2; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }  else if (pacman_row > 7) {
                            for(int row = pacman_row - 2; row <= 9; row++) {
                                if (map[row][col].entity == DOT) {
                                    point_count = point_count + 10;
                                } else if (map[row][col].entity == WALL) {
                                    point_count = point_count + 0;
                                } else if (map[row][col].entity == APPLE) {
                                    point_count = point_count + 20;
                                } else if (row == apple_row && col == apple_col) {
                                    point_count = point_count + 20;
                                }else if (map[row][col].entity == BANANA) {
                                    point_count = point_count + 20;
                                }
                                if (row != pacman_row || col != pacman_col) {
                                    map[row][col].entity = EMPTY_ENTITY;
                                } 
                            }
                        }
                    }
                }
            }else if (map[pacman_row][pacman_col].entity == BANANA) {
                for (int col = pacman_col; col <= 9 &&
                 map[pacman_row][col].entity != WALL; col++) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int col = pacman_col; col >= 0 &&
                 map[pacman_row][col].entity != WALL; col--) {
                    if (map[pacman_row][col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[pacman_row][col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[pacman_row][col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[pacman_row][col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[pacman_row][col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row <= 7 &&
                 map[row][pacman_col].entity != WALL; row++) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
                for (int row = pacman_row; row >= 0 &&
                 map[row][pacman_col].entity != WALL; row--) {
                    if (map[row][pacman_col].entity == DOT) {
                        point_count = point_count + 10;
                    } else if (map[row][pacman_col].entity == WALL) {
                        point_count = point_count + 0;
                    } else if (map[row][pacman_col].entity == APPLE) {
                        point_count = point_count + 20;
                    } else if (map[row][pacman_col].entity == BANANA) {
                        point_count = point_count + 20;
                    } 
                    map[row][pacman_col].entity = EMPTY_ENTITY;
                }
            }
            check_point = 0;
            for (int check_col = 0; check_col <= 9; check_col++) {
                for (int check_row = 0; check_row <= 7; check_row++) {
                    if (map[check_row][check_col].entity != DOT) {
                        check_point++;
                    }
                }
            }
            i++;
            if (check_point == 79) {
                printf("Game won! You got %d points.\n", point_count);
            } else if (check_point != 79 && move_comand != 'p'){
                print_map(map, pacman_row, pacman_col);
                printf("Enter command: ");
            } 
        } else if (move_comand == 'p') {
            printf("You have %d points!\n", point_count);
            print_map(map, pacman_row, pacman_col);
            printf("Enter command: ");
        } 
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your functions here


///////////////////////////////////////////////////////////////////////////////
/////////////////////////// PROVIDED FUNCTIONS  ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void initialise_map(struct tile map[NUM_ROWS][NUM_COLS]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            map[row][col].entity = EMPTY_ENTITY;
            map[row][col].enemy.move_direction = LEFT;
            map[row][col].enemy.is_present = FALSE;
        }
    }
}

void print_map(
    struct tile map[NUM_ROWS][NUM_COLS],
    int pacman_row,
    int pacman_col
) {
    for (int i = 0; i < NUM_COLS; i++) {
        printf("----");
    }
    printf("-\n");
    for (int row = 0; row < NUM_ROWS; row++) {
        printf("|");
        for (int col = 0; col < NUM_COLS; col++) {
            if (map[row][col].entity == WALL) {
                printf("|||");
            } else if (row == pacman_row && col == pacman_col) {
                printf("^_^");
            } else if (map[row][col].enemy.is_present == TRUE) {
                printf("O_O");
            } else if (map[row][col].entity == DOT) {
                printf(" . ");
            } else if (map[row][col].entity == APPLE) {
                printf(" a ");
            } else if (map[row][col].entity == BANANA) {
                printf(" b ");
            } else if (map[row][col].entity == POWER_UP) {
                printf("<o>");
            } else if (map[row][col].entity == STAIRCASE_UP) {
                printf("__/");
            } else if (map[row][col].entity == STAIRCASE_DOWN) {
                printf("\\__");
            } else {
                printf("   ");
            }

            printf("|");
        }
        printf("\n");
        for (int i = 0; i < NUM_COLS; i++) {
            printf("----");
        }
        printf("-\n");
    }
}