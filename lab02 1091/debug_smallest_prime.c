// debug_smallest_prime.c
//
// This is a C program that determines if the smallest prime factor of a
// positive number is 2, 3, or 5.
//
// Otherwise, the program tells you that it's lowest prime factor is higher
// then 5
//
// Gab Steiner, 2023

#include <stdio.h>

int main(void) {
    // Scan the number.
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Find it's lowest factor.
    if (number %2 == 0) {
        printf("The lowest prime factor is 2.\n");
    } else if (number %3 == 0) {
        printf("The lowest prime factor is 3.\n");
    } else if (number %5 == 0) {
        printf("The lowest prime factor is 5.\n");
    } else {
        printf("The lowest prime factor of %d is higher than 5\n", number);
    }
    
    return 0;
}
