#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int is_set(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = is_set(head);
    printf("%d\n", result);

    return 0;
}


// return 1 if the list is a set
int is_set(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *current = head;
    while (current != NULL) {
        struct node *checker = current->next;
        while (checker != NULL) {
            if (current->data == checker->data) {
                // A duplicate has been found
                return 0;
            }
            checker = checker->next;
        }
        current = current->next;
    }
    // No duplicates found
    return 1;
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
