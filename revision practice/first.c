#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int sum = 0, num = 0;
    
    num = atoi(argv[1]);
    sum = sum + num;
    
    printf("Sum: %d", sum);
    
    return 0;
}


struct node {
    int          data;
    struct node *next;
};

struct node *list_append(struct node *list1, struct node *list2){
    struct node *curr = list1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = list2;
    return list1;
}

int identical(struct node *head1, struct node *head2) {
    
}



while (strcmp(current->name, insert_before_name) != 0 && current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        insert_route_i->next = logbook->routes;
        logbook->routes = insert_route_i;
    } else {
        previous->next = insert_route_i;
        insert_route_i->next = current;
    }


void insert_route (struct route *insert_route_i, struct logbook *logbook, char *insert_before_name, int *route_count) {
    struct route *current = logbook->routes;
    struct route *previous = NULL;
    int check_name = 0;
    if (current == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", insert_before_name);
        return;
    } 
    while (current != NULL) {
        if (strcmp(current->name, insert_before_name) == 0) {
            check_name = 1;
            break;
        }
        current = current->next;
    }
    if (check_name == 0) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n", insert_before_name);
        return;
    }
    current = logbook->routes;
    while (current->next != NULL) {
        if (strcmp(current->name, insert_route_i->name) == 0) {
            printf("ERROR: A route with the name '%s' already exists in this logbook\n", insert_route_i->name);
            return;
        } else {
            current = current->next;
        }
    } 
    if (insert_route_i->difficulty > 39 || insert_route_i <= 0) {
        printf("ERROR: Route difficulty must be between 1 and 39\n");
        return;
    } else if (insert_route_i->length <= 0 || insert_route_i->length > 60) {
        printf("ERROR: Route length must be between 1m and 60m\n");
        return;
    }
    current = logbook->routes;
    if (strcmp(current->name, insert_before_name) == 0) {
        insert_route_i->next = current;
        logbook->routes = insert_route_i;
        printf("Route '%s' inserted successfully!\n", insert_route_i->name);
        route_count++;
        return;
    }
    current = logbook->routes;    
    while (strcmp(current->name, insert_before_name) != 0 && current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous != NULL) {
        previous->next = insert_route_i;
    }
    previous->next = insert_route_i;
    insert_route_i->next = current;
    route_count++;
    printf("Route '%s' inserted successfully!\n", insert_route_i->name);
}
