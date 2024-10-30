#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// DO NOT CHANGE THIS STRUCT
struct node {
    struct node *next;
    int          data;
};

// ordered_insert should create a new node with the specified value,
// and add it to the list such that the list remains in ascending order.
//
// ordered_insert should return the head of the list.
struct node *ordered_insert(struct node *head, int value) {

    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = value;
    new->next = NULL;

    // If the new node should be the new head or the list is empty
    if (head == NULL || value < head->data) {
        new->next = head;
        head = new;
    } else {
        // Find the insertion point
        struct node *curr = head;
        while (curr->next != NULL && curr->next->data < value) {
            curr = curr->next;
        }
        // Insert the new node
        new->next = curr->next;
        curr->next = new;
    }

    return head;
}


// If you want, you can write this function to use for debugging.
// It gets called in the main function below.
// If you don't want to write this function, you can just run the
// autotests (which have their own print_list function).
static void print_list(struct node *head) {
    printf("TODO: write code here to print the list "
           "(or just run the autotest)\n");
}

////////////////////////////////////////////////////////////////////////
//               DO NOT CHANGE THE CODE BELOW                         //
////////////////////////////////////////////////////////////////////////

struct node *ordered_insert(struct node *head, int value);
struct node *strings_to_list(int len, char *strings[]);
static void print_list(struct node *head);


// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: you must have at least one argument\n");
        return 1;
    }

    // Grab the first argument to use as the value to insert.
    int to_insert = atoi(argv[1]);

    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 2, &argv[2]);

    // If you're getting an error here,
    // you have returned an uninitialized value
    struct node *new_head = ordered_insert(head, to_insert);
    printf("The new list is: ");
    print_list(new_head);

    return 0;
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
