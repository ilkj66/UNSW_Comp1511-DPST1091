// z5528914

#include <stdio.h>

int main(void) {

    int num_stu, num_tut;
    
    printf ("Please enter the number of students and tutors: ");
    scanf ("%d", &num_stu);
    scanf ("%d", &num_tut);
    int total = num_stu + num_tut;
    printf ("%d + %d = %d\n", num_stu, num_tut, total);


    return 0;
}
