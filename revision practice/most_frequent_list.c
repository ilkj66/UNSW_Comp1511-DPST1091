#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned
int most_frequent(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *curr = head;
    struct node *outside = head;
    int check_count = 0;
    int biggest_count = 0;
    int checkdata;
    int biggest = head->data;
    while (outside->next != NULL) {
        checkdata = outside->data;
        curr = head;
        while (curr->next != NULL) {
            if (checkdata == curr->data) {
                check_count++;
            }
            curr = curr->next;
        }
        if (check_count > biggest_count) {
            biggest_count = check_count;
            biggest = checkdata;
        }
        check_count = 0;
        outside = outside->next;
    }
    return biggest;
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
