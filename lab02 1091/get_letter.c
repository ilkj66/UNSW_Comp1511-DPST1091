//z5528914

#include <stdio.h>

int main(void) {
    char choice;
    int index;
    printf("Uppercase: ");
    scanf("%c", &choice);
    printf("Index: ");
    scanf("%d", &index);
    if (choice == 'y') 
    { 
        if (index >= 1 && index <= 26) 
        { 
            char uppercase_num = 'A' + (index - 1);
            printf("The letter is %c\n", uppercase_num);
        }
    }
    else if (choice == 'n') 
    { 
        if (index >= 1 && index <= 26)
        {
            char lowercase_num = 'a' + (index - 1);
            printf("The letter is %c\n", lowercase_num);
        }
    }
    return 0;
}
    
    
