// z5528914
#include <stdio.h>

int remove_duplicates(int length, int source[length], int destination[length]);

int main(void) {
    int length;
    remove_duplicates(length, source[length], destination[length]);
    return 0;
}

int remove_duplicates(int length, int source[length], int destination[length]) {
    int i = 0;
    int a = 0;
    int new_length = length;
    while(i <= length) {
        while(a < i) {
            if(source[i] == destination[a]) {
                a++;
                new_length--;
            } else {
                i = i + 1;
                }
        }
        destination[i] = source[i];
        i++;
    }
}