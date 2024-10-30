// z5528914
#include <stdio.h>

#define FLAT_EYEBROW 'a'
#define SQUIGGLE_EYEBROW 'b'
#define LEFT_ANGRY_EYE 'c'
#define RIGHT_ANGRY_EYE 'd'
#define UP_NOSE 'e'
#define SQUIGGLE_NOSE 'f'
#define SMILE_MOUTH 'g'
#define GRUMPY_MOUTH 'h'
#define SURPRISE_MOUTH 'i'

int main(void) {

    printf("How do you want to build a face?: ");


    char first_eye;
    scanf("%c", &first_eye);

    char left_eyebrow = '?';

    if (first_eye == FLAT_EYEBROW) {
        left_eyebrow = '_';
    } else if (first_eye == SQUIGGLE_EYEBROW) {
        left_eyebrow = '~';
    } else if (first_eye == LEFT_ANGRY_EYE) {
        left_eyebrow = '\\';
    } else if (first_eye == RIGHT_ANGRY_EYE) {
        left_eyebrow = '/';
    }

    char eye_nose = '?';
    scanf("%c", &eye_nose);

    char right_eyebrow = '?';

    if (eye_nose >= FLAT_EYEBROW && eye_nose <= RIGHT_ANGRY_EYE) {
        if (eye_nose == FLAT_EYEBROW) {
            right_eyebrow = '_';
        } else if (eye_nose == SQUIGGLE_EYEBROW) {
            right_eyebrow = '~';
        } else if (eye_nose == LEFT_ANGRY_EYE) {
            right_eyebrow = '\\';
        } else if (eye_nose == RIGHT_ANGRY_EYE) {
            right_eyebrow = '/';
        }

    } else {
        right_eyebrow = left_eyebrow;
    }

    printf("%c %c\n", left_eyebrow, right_eyebrow);
    printf("O O\n");

    char nose;
    
    if (eye_nose <= RIGHT_ANGRY_EYE) {
        scanf("%c", &nose);
    } else {
        nose = eye_nose;
    }

    if (nose == UP_NOSE) {
        printf(" ^ \n");
    } else if (nose == SQUIGGLE_NOSE) {
        printf(" ~ \n");
    }

    char mouth;
    scanf("%c", &mouth);

    if (mouth == SMILE_MOUTH) {
        printf("\\_/\n");
    } else if (mouth == GRUMPY_MOUTH) {
        printf("/-\\\n");
    } else if (mouth == SURPRISE_MOUTH) {
        printf(" o \n");
    }

    return 0;
}