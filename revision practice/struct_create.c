#include <stdio.h>
#include <stdlib.h>

// Do not edit this struct. You may use it exactly as it is
// but you cannot make changes to it
struct numbers {
    int first;
    int second;
};

// create an instance of the struct and return a pointer to it
struct numbers *struct_create(int a, int b) {
    // PUT YOUR CODE HERE (you must change the next line!)
    struct numbers *new = malloc(sizeof(struct numbers));
    new->first = a;
    new->second = b;
    return new;
}

// This is a simple main function which could be used
// to test your struct_create function.
// It will not be marked.
// Only your struct_create function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    struct numbers* n = struct_create(first, second);
    
    printf("%d, %d\n", n->first, n->second);
    return 0;
}
