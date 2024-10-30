
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct passenger {
    double height;
    int num_bags;
};

int main(void) {

    struct passenger my_array[SIZE];
    double heig;
    int sum = 0;
    // printf("Total of %d bags from people over %lf\n", TODO, TODO);
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("Enter height & number of bags: ");
        scanf("%lf %d", &my_array[i].height, &my_array[i].num_bags);
    }
    printf("Select height: ");
    scanf("%lf", &heig);
    int k;
    for (k = 0; k < SIZE; k++) {
        if (my_array[k].height >= heig) {
            sum = my_array[k].num_bags + sum;
        }
    }
    printf("Total of %d bags from people over %lf\n", sum, heig);

    return 0;
}