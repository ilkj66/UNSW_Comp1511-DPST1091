#include <stdio.h>
int main(int argc, char *argv[]) {
    int i = 0;
    while (argv[i] != '\0') {
        if (argv[i] >= 0 && argv[i] <= 9) {
            putchar(argv[i] + 'A');
        } else {
            putchar();
        }
    }
    return 0;
}