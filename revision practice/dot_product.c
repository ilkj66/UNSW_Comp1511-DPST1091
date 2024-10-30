// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE

#include <stdio.h>

int dot_product(int length, int vector1[], int vector2[]);

// This is a simple main function that you can use to test your array_sum_prod
// function.
// It will not be marked - only your function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your function directly.
// Any changes that you make to this main function will not affect the autotests.
int main(void) {

    //Feel free to modify any of these tests.
    int test_vector1[] = {5, 10, 3};
    int test_vector2[] = {5, 3, 17};
    int test_vector3[] = {-5, 0, 1};

    int result = dot_product(3, test_vector1, test_vector2);

    printf("Result: %d\n", result);

    int result2 = dot_product(3, test_vector2, test_vector3);

    printf("Result2: %d\n", result2);

    return 0;
}



// Calculates the dot product of two arrays of the same length.
//
// Parameters:
//  `length`: the length of both arrays
//  `vector1`: The first array
//  `vector2`: The second array
//
// Returns: the dot product of `vector1` and `vector2`.
int dot_product(int length, int vector1[], int vector2[]) {
    // TODO: Complete this function
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum + (vector1[i] * vector2[i]);
    }
    return sum;
}
