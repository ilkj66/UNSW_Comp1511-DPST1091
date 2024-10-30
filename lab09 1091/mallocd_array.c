// <PROGRAM-DESCRIPTION>
// Written by Yiming HE z5528914
// on MARCH 13

#include <stdio.h>
#include <stdlib.h>
//TODO add correct #include for malloc

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////

int *scan_array(int size);
double calculate_average(int *array, int size);

int main (void) {

    int size;
    printf("Enter size: ");
    scanf(" %d", &size);
    if (size <= 0) {
        printf("Invalid Size\n");
        return 1;
    }
    printf("Enter %d integers:\n", size);
    int *array = scan_array(size);

    printf("The average of all values in the array is: %.2lf\n", 
           calculate_average(array, size));

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// A function which scans in `size` integers and stores them into a 
// malloc'd array.
// returns: a pointer to the malloc'd array
int *scan_array(int size) {
    // TODO: 1. create a MALLOC'd array of size `size`
    int *array = malloc(size * sizeof(int));
    // TODO: 2. Loop through and scan values into the array.
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    // TODO 3.delete the following line and return the array.
    return array;
}

// Given an integer array and it's size, 
// returns the sum of all elements inside the array, divided by the size of the
// array.
double calculate_average(int *array, int size) {
    
    // TODO calculate the sum of the array.
    int total = 0;
    for (int i = 0; i < size; i++) {
        total = total + array[i];
    }
    double avg = (double)total / size;

    return avg;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
