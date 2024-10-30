#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

void rotate_thirteen(char *string);
char rotate_one(char c);
int strings_equal(char *string1, char *string2);

int main(int argc, char *argv[]) {
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    int i = 0;
    char c;
    while ((c = string[i]) != '\0') {
        if (c >= 'A' && c <= 'Z') {
            string[i] = ((c - 'A' + 13) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            string[i] = ((c - 'a' + 13) % 26) + 'a';
        }
        i++;
    }
}


char rotate_one(char c) {
    if (c >= 'a' && c < 'z') {
        return c + 1;
    } else if (c == 'z') {
        return 'a';
    } else if (c >= 'A' && c < 'Z') {
        return c + 1;
    } else if (c == 'Z') {
        return 'A';
    }
    return c;  // Non-alphabetic characters are not changed
}


int strings_equal(char *string1, char *string2) {
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            return 0;  // Strings are not equal
        }
        i++;
    }
    return string1[i] == string2[i];  // Check if both strings ended at the same length
}
