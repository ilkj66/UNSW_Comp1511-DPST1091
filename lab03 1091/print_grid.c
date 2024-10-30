// z5528914

#include <stdio.h>

int main(void) {
    int size;
    int row, col;
    printf("Enter size: ");
    scanf("%d", &size);
    row = 0;
    while(row < size) {
        col = 0;
        while(col < size) {
            printf("(%d, %d)",row, col);
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}