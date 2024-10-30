#include <stdio.h>

int *get_num_ptr(void);
int *x;
int main(void) {
    int *num = get_num_ptr();

    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    *x = 42;
    return x;
}