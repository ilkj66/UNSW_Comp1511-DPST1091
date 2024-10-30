// z5528914 YIMING HE


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0, num = 0;
    int i = 1;
    while (i < argc) {
        num = atoi(argv[i]);
        sum = sum + num;
        i++;
    }
    printf("Sum: %d\n", sum);
    
    return 0;
}