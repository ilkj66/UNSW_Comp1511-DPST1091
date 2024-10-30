// z5528914

#include <stdio.h>

char abc(char x, int y)
{
    int z;
 
    if(y >= 26)
    {
        while(y >= 26)
        {
            y = y - 26;
    }
    }
    else if(y <= - 26)
 {
        while(y <= 0)
  {
   y = y + 26;
  }
 }
    z = x + y ;
 
    return z;
} 

int cba(char x, int y)
{
    int z;
 
    if(y >= 26)
 {
        while(y >= 26)
  {
            y = y - 26;
  }
 }
    else if(y <= - 26)
 {
    while(y <= 0)
  {
            y = y + 26;
    }
    }
    z = x - y ;
 
    return z;
}
 
 
// This main function scans a message then enciphers it by some given inputs
int main() 
{
    // Have a think about how we might implement this with a `struct message`
    // once we've covered structs in the Thursday lecture!
    char letter1;
    char letter2;
    char letter3;
    char letter4;
    char choose;
    int num1, num2, num3, num4;
    char p1, p2, p3, p4;
    
    // Scan message into the four characters
    printf("Message: ");
    scanf("%c%c%c%c", &letter1, &letter2, &letter3, &letter4);
    getchar();
    printf("Would you like to encipher or decipher this message (e/d)? ");
    scanf("%c", &choose);
    
    
    if(choose == 'e')
    {
         printf("Enter numbers to encipher by: ");
         scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
         p1 = abc(letter1, num1);
         p2 = abc(letter2, num2);
         p3 = abc(letter3, num3);
         p4 = abc(letter4, num4);
    }
    
    else 
    {
         printf("Enter numbers to decipher by: ");
         scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
         p1 = cba(letter1, num1);
         p2 = cba(letter2, num2);
         p3 = cba(letter3, num3);
         p4 = cba(letter4, num4);
    }
     
    printf("%c%c%c%c\n", p1, p2, p3, p4);

    // TODO: Encipher the letters
    return 0;
}