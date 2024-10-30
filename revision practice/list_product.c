#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int product(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = product(head1, head2);
    printf("%d\n", result);

    return 0;
}

// product should return the sum of the elements in list1 multiplied by 
// the corresponding element in list2
// if one list is longer than the other, the extra list elements are ignored 
int product(struct node *head1, struct node *head2) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *curr1 = head1;
    struct node *curr2 = head2;
    if (curr1 == NULL || curr2 == NULL) {
        return 0;
    }
    int sum = 0;
    
    while (curr1 != NULL && curr2 != NULL) {
        sum += (curr1->data * curr2->data);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return sum;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
