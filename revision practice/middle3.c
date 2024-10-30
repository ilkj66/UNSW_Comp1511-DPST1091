// Program to scan in three integers and print out the middle one.

#include <stdio.h>

struct numbers {
    int first;
    int second;
    int third;
};

int main(void) {
    // DO NOT CHANGE CODE BELOW HERE
    struct numbers nums;
    printf("Enter integer: ");
    scanf("%d", &nums.first);

    printf("Enter integer: ");
    scanf("%d", &nums.second);

    printf("Enter integer: ");
    scanf("%d", &nums.third);
    // DO NOT CHANGE CODE ABOVE HERE

    // ADD CODE BELOW HERE
    // TODO: print out the middle integer of the three scanned in
    
    int middle;

    if ((nums.first <= nums.second && nums.second <= nums.third) || (nums.third <= nums.second && nums.second <= nums.first))
        middle = nums.second;
    else if ((nums.second <= nums.first && nums.first <= nums.third) || (nums.third <= nums.first && nums.first <= nums.second))
        middle = nums.first;
    else
        middle = nums.third;


    return 0;
}
