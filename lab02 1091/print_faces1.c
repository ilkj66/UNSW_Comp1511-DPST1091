// z5528914

#include <stdio.h>

int main(void) {
    printf("How do you want to build a face?:");
    char part1 = '\0', part2 = '\0', part3 = '\0';
    
    if (part2 >= 'a' && part2 <= 'd') {
        char part4;
        scanf(" %c", &part4);
        if (part1 == 'a') {
            printf(" _");
        } else if (part1 == 'b') {
            printf(" ~");
        } else if (part1 == 'c') {
            printf(" \\");
        } else if (part1 == 'd') { 
            printf(" /");
        }
        scanf(" %c", &part2);
        if (part2 == 'a') {
            printf(" _\n O O\n");
        } else if (part2 == 'b') {
            printf(" ~\n O O\n");
        } else if (part2 == 'c') {
            printf(" \\\n O O\n");
        } else if (part2 == 'd') {
            printf(" /\n O O\n");
        }
        scanf(" %c", &part3);
        if (part3 == 'e') {
            printf("  ^\n");
        } else if (part3 == 'f') {
            printf("  ~\n");
        }
        scanf(" %c", &part4);
        if (part4 == 'g') {
            printf(" \\_/\n");
        } else if (part4 == 'h') {
            printf(" /-\\\n");
        } else if (part4 == 'i') {
            printf("  o\n");
        }
    } else if (part2 >= 'e' && part2 <= 'i') {
        scanf(" %c", &part1);
        if (part1 == 'a') {
            printf(" _ _\n O O\n");
        } else if (part1 == 'b') {
            printf(" ~ ~\n O O\n");
        } else if (part1 == 'c') {
            printf(" \\ \\\n O O\n");
        } else if (part1 == 'd') { 
            printf(" / /\n O O\n");
        }
        scanf(" %c", &part2);
        if (part2 == 'e') {
            printf("  ^\n");
        } else if (part2 == 'f') {
            printf("  ~\n");
        }
        scanf(" %c", &part3);
        if (part3 == 'g') {
            printf(" \\_/\n");
        } else if (part3 == 'h') {
            printf(" /-\\\n");
        } else if (part3 == 'i') {
            printf("  o\n");
        }
    }
    return 0;
}