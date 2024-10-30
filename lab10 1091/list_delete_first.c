// z5528914 yiming he

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LIST_LEN 100

struct node {
    struct node *next;
    int          data;
};

struct node *delete_first(struct node *head);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);
static void free_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(void) {
    // get list size
    int list_size;
    printf("Total numbers: ");
    scanf(" %d", &list_size);

    // read in numbers
    int list[MAX_LIST_LEN] = {0};
    int index_count = 0;
    while (index_count < list_size && scanf(" %d", &list[index_count])) {
        index_count++;
    }

    // create linked list from input numbers
    struct node *head = NULL;
    if (index_count > 0) {
        // list has elements
        head = array_to_list(list_size, list);
    }

    struct node *new_head = delete_first(head);
    print_list(new_head);
    free_list(new_head);

    return 0;
}


//
// Delete the first node in list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_first(struct node *head) {
    if (head == NULL) {
        return NULL; 
    }
    struct node *temp = head;
    head = head->next; 
    free(temp); 
    // PUT YOUR CODE HERE (change the next line!)
    return head;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of ints
struct node *array_to_list(int len, int array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;

        i--;
    }

    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

// DO NOT CHANGE THIS FUNCTION
// free linked list
static void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}
