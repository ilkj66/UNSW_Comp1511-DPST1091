// A simple program that figures out how many slices of
// bread I can snack on while making sandwiches for my party!

// Written by Paula Tennent (z5255101) on 4/2/23
// Tested by [student]


#include <stdio.h>

int main(void) {

    printf("How many slices of bread do you have? ");

    int slices;
    scanf("%d", &slices);

    int snack;
    int sandwiches;
    // if I have an odd number of slices, I can snack
    // on 1 slice.
    if (slices >= 0) {
        if (slices % 2 == 0) {
            snack = 2;
            sandwiches = (slices / 2) - 1;
        }
    

        // if I have an even number of slices, I can snack
        // on 2 slices!
        else {
            snack = 1;
            sandwiches = (slices - 1) / 2;
        }
        printf("You can snack on %d slices of bread", snack);
        printf(" and make %d sandwiches!\n", sandwiches);
    }
    return 0;
}
