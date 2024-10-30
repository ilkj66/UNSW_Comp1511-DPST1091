//z5528914

#include <stdio.h>
#include <math.h>

int main(void) {
    int num1, num2;
    char num_type;
    printf("Enter instruction: ");
    while (scanf(" %c", &num_type) != EOF) {
        if (num_type == '1') {
            scanf("%d", &num1);
            printf("%d", num1 * num1);
        } else if (num_type == '2') {
            scanf("%d %d", &num1, &num2);
            int rslt = pow(num1, num2);
            printf("%d", rslt);
        }
        printf("\nEnter instruction: ");
    }
    return 0;
} 