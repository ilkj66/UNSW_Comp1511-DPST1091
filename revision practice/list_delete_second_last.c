#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_second_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_second_last(head);
    print_list(new_head);

    return 0;
}


//
// Delete the second last node in the list.
// The deleted node is freed.
// The head of the list is returned.
//
struct node *delete_second_last(struct node *head) {

   if (head == NULL || head->next == NULL) {
        return head;  // Return the head unchanged (NULL if empty, the single node if one node)
    }

    // If the list has only two nodes, remove the first node
    if (head->next->next == NULL) {
        struct node *temp = head;
        head = head->next;  // Make the second node the new head
        free(temp);  // Free the first node
        return head;
    }

    // Find the third-to-last node
    struct node *current = head;
    while (current->next->next->next != NULL) {
        current = current->next;
    }

    // Current now points to the third-to-last node
    struct node *to_delete = current->next;  // This is the second-to-last node
    current->next = to_delete->next;  // Bypass the second-to-last node
    free(to_delete);  // Free the second-to-last node

    return head;
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

