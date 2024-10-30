//z5528914
// YIMING HE


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// DO NOT CHANGE THESE STRUCTS
struct list {
    struct node *head;
};

struct node {
    struct node *next;
    int          data;
};

void insert_tail(int value, struct list *list);
struct list *array_to_list(int len, int array[]);
void print_list(struct list *list);

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main() {
    // Need to read in a number of ints into an array
    printf("How many numbers in initial list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = {0};
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read])) {
        n_read++;
    }

    // create linked list from first set of inputs
    struct list *list = NULL;
        // list has elements
    list = array_to_list(n_read, initial_elems);


    printf("Enter value to insert: ");
    int value;
    scanf("%d", &value);
    insert_tail(value, list);
    print_list(list);

    return 0;
}


// Insert a new node containing value at the end of the linked list.
// Parameters:
//      `int value`         : The value to insert.
//      `struct list *list` : a struct * containing the head pointer of the 
//      linked list.
void insert_tail(int value, struct list *list) {
    // PUT YOUR CODE HERE
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct list *array_to_list(int len, int array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }

    struct list *list = malloc(sizeof(struct list));
    list->head = head;
    return list;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct list *list) {
    printf("[");    
    struct node *n = list->head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
