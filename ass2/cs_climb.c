// Program name
//
// This program was written by YIMING HE z5528914
// on March 13
//
// TODO: Description of program


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
///////////////////////////      Constants       ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided constants
#define MAX_STR_LEN 20
#define HELP_COMMAND '?'

// Provided enums
// This enum only has to be used in Stage 3.1 onwards
enum attempt_type {FIRST_GO, SUCCESS, FAIL, INVALID_TYPE};

// TODO: Your #defines/enums can go here:

////////////////////////////////////////////////////////////////////////////////
//////////////////////////  USER DEFINED TYPES  ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Any additional structs you want to add can go here:

// Provided structs

// Represents a single climbing route in the logbook
struct route {
    // The name of the climbing route
    char name[MAX_STR_LEN];
    // The difficulty of the route
    int difficulty;
    // The length of the route in metres
    int length;
    // A pointer to the next `struct route` in the logbook 
    struct route *next;
    struct attempt *attempts;
};

// Represents the logbook that contains info on each climbing route
struct logbook {
    // A pointer to the first `struct route` in the list
    struct route *routes;
};

struct attempt {
    char climber[MAX_STR_LEN];
    enum attempt_type type;
    int rating;
    struct attempt *next;
};
 
////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void print_usage(void); 
void print_one_route(int position, struct route *route);
void scan_string(char string[MAX_STR_LEN]);
enum attempt_type scan_attempt_type();
void print_one_attempt(
    char climber[MAX_STR_LEN], 
    enum attempt_type type, 
    int rating
);

// Additional provided function prototypes
// You won't need to use these functions!
// We use them just to implement some of the provided helper functions.
int scan_token(char *buffer, int buffer_size);
enum attempt_type string_to_type(char *type_str);
void type_to_string(char *buf, enum attempt_type type);
void add_route_to_logbook(struct logbook *logbook, struct route *new_route);
void print_p (struct logbook *logbook, int route_count);
void check_route_error(struct route *new_route, struct logbook *logbook, int *route_count);
void check_difficulty(struct logbook *logbook, int difficulty_max, int difficulty_min, int route_count);
void insert_route (struct route *insert_route_i, struct logbook *logbook, char *insert_before_name, int *route_count);
void change_route_length (struct logbook *logbook, char *search_begin, char *search_end, int *change_num);
void change_position_function (struct logbook *logbook, char *change_p1, char *change_p2);
//////////////
struct attempt *create_attempt(char climber[MAX_STR_LEN], enum attempt_type type, int rating);
void add_attempt (struct logbook *logbook, struct attempt *new_attempt, char *route_name);
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct logbook *create_logbook();
struct route *create_route(
    char name[MAX_STR_LEN], 
    int difficulty, 
    int length
);

// TODO: Put your function prototypes here

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    printf("Welcome to 1511 Climb! \n");
    printf("Log all of your climbing adventures here! \n");

    // STAGE 1.1
    // You should call your `create_logbook()` function here!
    struct logbook *logbook = create_logbook();
    printf("Enter command: ");
    // STAGE 1.2
    // TODO: Write your command loop
    char command;
    int route_count = 0;
    while (scanf(" %c", &command) != EOF) {
        if (command == HELP_COMMAND) {
            print_usage();
        } else if (command == 'r') {
            char name[MAX_STR_LEN];
            int difficulty, length;
            scan_string(name);
            scanf(" %d %d", &difficulty, &length);
            struct route *new_route = create_route(name, difficulty, length);
            new_route->next = NULL;
            check_route_error(new_route, logbook, &route_count);
            //add_route_to_logbook(logbook, new_route);
        } else if (command == 'p') {
            print_p (logbook, route_count);
        } else if (command == 'f') {
            int difficulty_min, difficulty_max;
            scanf(" %d %d", &difficulty_min, &difficulty_max);
            if (difficulty_min <= 0 || difficulty_max > 39 
            || difficulty_min > difficulty_max) {
                printf("ERROR: Difficulty range invalid!\n");
            } else {
                printf("Routes between difficulty %d and %d:\n",
                 difficulty_min, difficulty_max);
                check_difficulty(logbook, difficulty_max, difficulty_min, route_count);
            }
        } else if (command == 'i') {
            char insert_route_name[MAX_STR_LEN], insert_before_name[MAX_STR_LEN];
            int insert_route_difficulty, insert_route_length;
            scan_string(insert_route_name);
            scanf(" %d %d", &insert_route_difficulty, &insert_route_length);
            scan_string(insert_before_name);
            struct route *insert_route_i = malloc(sizeof(struct route));
            insert_route_i = create_route(insert_route_name,
             insert_route_difficulty, insert_route_length);
            insert_route(insert_route_i, logbook, insert_before_name, &route_count);
        } else if (command == 'l') {
            char search_begin[MAX_STR_LEN], search_end[MAX_STR_LEN];
            int change_num;
            scan_string(search_begin);
            scan_string(search_end);
            scanf(" %d", &change_num);
            change_route_length (logbook, search_begin, search_end, &change_num);
        } else if (command == 's') {
            char change_p1[MAX_STR_LEN], change_p2[MAX_STR_LEN];
            scan_string(change_p1);
            scan_string(change_p2);
            change_position_function (logbook, change_p1, change_p2);
        } else if (command == 'a') {
            char climber[MAX_STR_LEN];
            int rating;
            enum attempt_type type;
            char route_name[MAX_STR_LEN];
            scan_string(climber);
            type = scan_attempt_type();
            scanf(" %d", &rating);
            scan_string(route_name);
            create_attempt(climber, type, rating);
            struct attempt *new_attempt = create_attempt(climber, type, rating);
            add_attempt (logbook, new_attempt, route_name);
            
        }
        printf("Enter command: ");
    }
    printf("\nGoodbye\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Allocate memory for a new struct logbook and return a pointer to it
//
// Parameters:
//      None
// 
// Returns:
//      new_logbook - a pointer to the newly created struct logbook
struct logbook *create_logbook() {
    struct logbook *new_logbook = malloc(sizeof(struct logbook));
    new_logbook->routes = NULL;
    return new_logbook;
}

// STAGE 1.1
// TODO: what does this function do?
//
// Parameters:
//      TODO
// 
// Returns:
//      TODO
struct route *create_route(
    char name[MAX_STR_LEN], 
    int difficulty, 
    int length
) {
    // STAGE 1.1
    // TODO: malloc, initialise and return a new route
    struct route *new_route = malloc(sizeof(struct route));
    strcpy(new_route->name, name);
    new_route->difficulty = difficulty;
    new_route->length = length;
    // hint: you will have to replace NULL in this return statement.
    return new_route;
}

// TODO: Put your functions here

void print_p (struct logbook *logbook, int route_count) {
    if (route_count > 0) {
        struct route *current = logbook->routes;
        for (int i = 1; i <= route_count; i++) {
            print_one_route(i, current);
            current = current->next;
        }
    } else {
        printf("There are no routes in this logbook!\n");
    }
}

void add_route_to_logbook(struct logbook *logbook, struct route *new_route) {
    if (logbook->routes == NULL) {
        logbook->routes = new_route;
    } else {
        struct route *current = logbook->routes;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_route;
    }
}

void check_route_error(struct route *new_route, 
struct logbook *logbook, int *route_count) {
    int check_route_error_point = 0;
    if (new_route->difficulty < 1 || new_route->difficulty > 39) {
        printf("ERROR: Route difficulty must be between 1 and 39\n");
        check_route_error_point++;
    } else if (new_route->length < 1 || new_route->length > 60) {
        printf("ERROR: Route length must be between 1m and 60m\n");
        check_route_error_point++;
    }
    struct route *current = logbook->routes;
    while (current != NULL) {
        if (strcmp(current->name, new_route->name) == 0) {
            printf("ERROR: A route with the name '%s' already exists in this logbook\n"
            , new_route->name);
            check_route_error_point++;
        }
        current = current->next;
    }
    if (check_route_error_point == 0) {
        printf("Route '%s' added successfully!\n", new_route->name);
        add_route_to_logbook(logbook, new_route);
        (*route_count)++;
    } else {
        free(new_route);
    }
}

void check_difficulty(struct logbook *logbook, int difficulty_max,
 int difficulty_min, int route_count) {
    struct route *current = logbook->routes;
    if (route_count > 0) {
        for (int i = 1; current != NULL; i++) {
            if (current->difficulty >= difficulty_min 
            && current->difficulty <= difficulty_max) {
                print_one_route(i, current);
            }
            current = current->next;
        }
    }
}

void insert_route(struct route *insert_route_i, struct logbook *logbook,
 char *insert_before_name, int *route_count) {

    if (insert_route_i->difficulty < 1 || insert_route_i->difficulty > 39) {
        printf("ERROR: Route difficulty must be between 1 and 39\n");
        return;
    } else if (insert_route_i->length < 1 || insert_route_i->length > 60) {
        printf("ERROR: Route length must be between 1m and 60m\n");
        return;
    }

    if (logbook->routes == NULL) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n"
        , insert_before_name);
        return;
    }

    struct route *current = logbook->routes;
    struct route *previous = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, insert_route_i->name) == 0) {
            printf("ERROR: A route with the name '%s' already exists in this logbook\n"
            , insert_route_i->name);
            return;
        }
        if (strcmp(current->name, insert_before_name) == 0) {
            found++; 
            break;
        }
        previous = current;
        current = current->next;
    }

    if (found == 0) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n"
        , insert_before_name);
        return;
    }

    if (previous == NULL) { 
        logbook->routes = insert_route_i;
    } else { 
        previous->next = insert_route_i;
    }
    insert_route_i->next = current;

    printf("Route '%s' inserted successfully!\n", insert_route_i->name);
    (*route_count)++;
}

void change_route_length (struct logbook *logbook, char *search_begin,
 char *search_end, int *change_num) {
    struct route *current = logbook->routes;
    int begin_check = 0, end_check = 0;

    while (current != NULL) {
        if (strcmp(current->name, search_begin) == 0) {
            begin_check++;
        } else if (strcmp(current->name, search_end) == 0) {
            end_check++;
        }
        current = current->next;
    }

    if (begin_check == 0) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n"
        , search_begin);
        return;
    } else if (end_check == 0 && strcmp(search_begin, search_end) != 0) {
        printf("ERROR: No route with the name '%s' exists in this logbook\n"
        , search_end);
        return;
    }

    current = logbook->routes;
    int i = 0, k = 0, t = 0;
    while (current != NULL) {
        if (strcmp (current->name, search_begin) == 0) {
            i = 1;
        } else if (strcmp(current->name, search_end) == 0) {
            t = 1;
        }
        if (i != 0 || t != 0) {
            k++;
        }
        if ((i == 1 || t == 1) && k > 0) {
            int changed_one = current->length + *change_num;
            if (changed_one <= 0 || changed_one > 60) {
                printf("ERROR: Invalid length change!");
                printf(" No route lengths have been changed\n");
                return;
            }
        }
        if (strcmp (current->name, search_begin) == 0 && t == 1) {
            i = 0;
            t = 0;
        } else if (strcmp(current->name, search_end) == 0 && i == 0) {
            i = 0;
            t = 0;
        }
        current = current->next;
    }

    current = logbook->routes;
    i = 0;
    t = 0;
    k = 0;
    while (current != NULL) {
        if (strcmp (current->name, search_begin) == 0) {
            i = 1;
        } else if (strcmp(current->name, search_end) == 0) {
            t = 1;
        }
        if (i != 0 || t != 0) {
            k++;
        }
        if ((i == 1 || t == 1) && k > 0) {
            int changed = current->length + *change_num;
            if (changed > 0 && changed <= 60) {
                printf("Length of '%s' updated from %dm to %dm\n"
                , current->name, current->length, changed);
                current->length = changed;
            } else {
                printf
                ("ERROR: Invalid length change! No route lengths have been changed\n");
            }
        } 
        if (strcmp (current->name, search_begin) == 0 && t == 1) {
            i = 0;
            t = 0;
        } else if (strcmp(current->name, search_end) == 0 && i == 0) {
            i = 0;
            t = 0;
        }
        current = current->next;
    }
}

void change_position_function(struct logbook *logbook, char *change_p1, char *change_p2) {
    if (strcmp(change_p1, change_p2) == 0) {
        printf("ERROR: Cannot swap '%s' with itself\n", change_p1);
        return;
    }

    struct route *prev_p1 = NULL, *prev_p2 = NULL,
     *route_p1 = NULL, *route_p2 = NULL, *current = logbook->routes;
    

    while (current != NULL) {
        if (route_p1 && route_p2) {
            break; 
        }

        if (!route_p1 && strcmp(current->name, change_p1) == 0) {
            route_p1 = current;
        } else if (!route_p2 && strcmp(current->name, change_p2) == 0) {
            route_p2 = current;
        }

        if (!route_p1) {
            prev_p1 = current;
        }
        if (!route_p2) {
            prev_p2 = current; 
        }
        current = current->next;
    }

    if (!route_p1 || !route_p2) {
        if (!route_p1) {
            printf("ERROR: No route with the name '%s' exists in this logbook\n"
            , change_p1);
            return;
        }
        if (!route_p2) {
            printf("ERROR: No route with the name '%s' exists in this logbook\n"
            , change_p2);
            return;
        }
    }

    if (prev_p1) {
        prev_p1->next = route_p2; 
    } else {
        logbook->routes = route_p2;
    }
    if (prev_p2) {
        prev_p2->next = route_p1; 
    } else {
        logbook->routes = route_p1;
    }

    struct route *temp;
    temp = route_p1->next;
    route_p1->next = route_p2->next;
    route_p2->next = temp;

    printf("'%s' swapped positions with '%s'!\n", change_p1, change_p2);
}

struct attempt *create_attempt(char climber[MAX_STR_LEN]
, enum attempt_type type, int rating) {
    struct attempt *new_attempt = malloc(sizeof(struct attempt));
    strcpy(new_attempt->climber, climber);
    if (type == INVALID_TYPE) {
        printf("ERROR: Attempt type invalid\n");
        return NULL;
    }
    new_attempt->type = type;
    if (rating < 0 || rating > 3) {
        printf("ERROR: Rating must be between 0 and 3\n");
        return NULL;
    }
    new_attempt->rating = rating;
    new_attempt->next = NULL;
    return new_attempt;
}

void add_attempt (struct logbook *logbook
, struct attempt *new_attempt, char *route_name) {
    struct route *curr_route = logbook->routes;
    int i = 0;
    while (curr_route != NULL) {
        if (strcmp(route_name, curr_route->name) == 0) {
            i = 1;
            break;
        }
        curr_route = curr_route->next;
    }
    if (i != 1) {
        printf("ERROR: No route with the name '[%s]' exists in this logbook\n"
        , route_name);
        return;
    }
    struct attempt *curr_att = curr_route->attempts;
    while (curr_att != NULL) {
        if (strcmp(curr_att->climber, new_attempt->climber) == 0) {
            if (new_attempt->type == FIRST_GO) {
                printf ("ERROR: [%s] has already attempted"
                " '[%s]' - they can't get it on their first go!\n"
                , new_attempt->climber, route_name);
            }
            return;
        }
        curr_att = curr_att->next;
    }
    curr_att->next = new_attempt;
    printf("Logged attempt of '%s' by %s\n", route_name, new_attempt->climber);
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////  PROVIDED FUNCTIONS  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Prints the 1511 Climb usage instructions,
// displaying the different commands and their arguments.
//
// Parameters:
//      None
// 
// Returns: 
//      None
void print_usage(void) {
    printf(
        "=====================[     1511 Climb     ]=====================\n"
        "      ===============[     Usage Info     ]===============      \n"
        "  r [name] [difficulty] [length]                                \n"
        "    Append a climbing route to the end of the logbook           \n"
        "  p                                                             \n"
        "    Print out all the climbing routes in the logbook            \n"
        "                                                                \n"
        "  f [difficulty_min] [difficulty_max]                           \n"
        "    Filter routes by difficulty                                 \n"
        "  i [name] [difficulty] [length] [route_to_insert_before]       \n"
        "    Insert a climbing route into the logbook before             \n"
        "    `route_to_insert_before`                                    \n"
        "  l [route_1] [route_2] [length_change]                         \n"
        "    Change length of all routes between `route_1` and `route_2` \n"
        "  s [route_1] [route_2]                                         \n"
        "    Swap 2 routes                                               \n"
        "                                                                \n"
        "  a [climber] [attempt_type] [rating] [route]                   \n"
        "    Add an attempt of `route` by `climber`                      \n"
        "  P                                                             \n"
        "    Print out all the routes and attempts in the logbook        \n"
        "  R [route]                                                     \n"
        "    Remove a route and all associated attempts                  \n"
        "  D [climber]                                                   \n"
        "    Delete all attempts by `climber`                            \n"
        "  d [climber_1] [climber_2]                                     \n"
        "    Duplicate all of `climber_2`s attempts for `climber_1`      \n"
        "                                                                \n"
        "  c [route_1] [route_2]                                         \n"
        "    Combine 2 routes                                            \n"
        "  L [route]                                                     \n"
        "    Print the climber leaderboard for `route`                   \n"
        "                                                                \n"
        "  ?                                                             \n"
        "    Show help                                                   \n"
        "================================================================\n"
    );
}

// Prints a single route, displaying its position in the logbook, name, grade 
// and length. 
//
// Parameters:
//      position    - The position of the route in the logbook (the first 
//                        route will be route_number 1, second will be 2, etc)
//      route       - A pointer to the struct route to be printed
//
// Returns:   
//      None
void print_one_route(int position, struct route *route) {
    int line_length = MAX_STR_LEN + 2;
    printf("/--------- \\/ ---------\\\n");

    char position_str[MAX_STR_LEN];
    sprintf(position_str, "Route #%d", position);
    int padding = line_length - strlen(position_str);
    printf(
        "|%*s%s%*s|\n", padding / 2, "", position_str, (padding + 1) / 2, ""
    );

    padding = line_length - strlen(route->name);
    printf("|%*s%s%*s|\n", padding / 2, "", route->name, (padding + 1) / 2, "");

    printf("|    Difficulty: %2d    |\n", route->difficulty);
    printf("|    Length (m): %2d    |\n", route->length);
    printf("\\--------- || ---------/\n");
}

// Scans a string into the provided char array, placing a '\0' at the end
// 
// Parameters:
//      string      - a char array of length MAX_STR_LEN to store the string 
//                    that is scanned in
// 
// Returns: 
//      None
// 
// Usage: 
// ```
//      char string[MAX_STR_LEN];
//      scan_string(string);
// ```
void scan_string(char string[MAX_STR_LEN]) {
    scan_token(string, MAX_STR_LEN);
}

// Scans a string and converts it to an enum attempt_type.
//
// Parameters: 
//      None
// 
// Returns:
//      The corresponding attempt_type, if the string was valid,
//      Otherwise, returns INVALID_TYPE.
// 
// Usage: 
// ```
//      enum attempt_type type = scan_attempt_type();
// ```
enum attempt_type scan_attempt_type(void) {
    char type[MAX_STR_LEN];
    scan_token(type, MAX_STR_LEN);
    return string_to_type(type);
}

// Prints a single attempt, displaying the climber name, attempt type and rating
//
// Parameters:
//      climber     - The name of the climber who attempted to climb a route
//      type        - The attempt type that was made (should be either 
//                    FIRST_GO, SUCCESS, or FAIL)
//      rating      - The star rating that the climber gave the route
// 
// Returns: 
//      None
void print_one_attempt(
    char climber[MAX_STR_LEN], 
    enum attempt_type type, 
    int rating
) {
    char type_string[MAX_STR_LEN];
    type_to_string(type_string, type);
    printf("        --> %s\n", type_string);
    printf("            Climber: %s\n", climber);
    printf("            Rating:  ");
    for (int i = 0; i < rating; i++) {
        printf("*");
    }
    printf("\n\n");
}

////////////////////////////////////////////////////////////////////////////////
////////////////////// ADDITIONAL PROVIDED FUNCTIONS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// You don't need to use any of these, or understand how they work!
// We use them to implement some of the provided helper functions.

// Scans a single word into `buffer`, ignoring whitespace
// 
// Parameters: 
//      buffer      - the string to store the scanned word
//      buffer_size - the maximum size of string that can be scanned (including 
//                    the null terminator)
// Returns: 
//      The number of chars scanned successfully
int scan_token(char *buffer, int buffer_size) {
    if (buffer_size == 0) {
        return 0;
    }

    char c;
    int i = 0;
    int num_scanned = 0;

    // Consume all leading whitespace
    scanf(" ");

    // Scan in characters until whitespace
    while (i < buffer_size - 1
        && (num_scanned = scanf("%c", &c)) == 1 
        && !isspace(c)) {
        buffer[i++] = c;
    }

    if (i > 0) {
        buffer[i] = '\0';
    }

    return num_scanned;
}

// Converts a string to the corresponding enum attempt_type
//
// Parameters: 
//      type_str    - The string to be converted
// 
// Returns: 
//      The matching enum attempt_type, or `INVALID_TYPE` if `type_str` matches 
//      no valid attempt type
enum attempt_type string_to_type(char *type_str) {
    int len = MAX_STR_LEN;

    if (strncasecmp(type_str, "first_go", len) == 0) {
        return FIRST_GO;
    }
    if (strncasecmp(type_str, "success", len) == 0) {
        return SUCCESS;
    } 
    if (strncasecmp(type_str, "fail", len) == 0) {
        return FAIL;
    } 

    return INVALID_TYPE;
}

// Converts an enum attempt_type to a string
// 
// Parameters:
//      buf         - The string to store the attempt type
//      type        - The enum attempt_type to be converted
// 
// Returns:
//      None
void type_to_string(char *buf, enum attempt_type type) {
    if (type == FIRST_GO) {
        strcpy(buf, "FIRST GO");
    } else if (type == SUCCESS) {
        strcpy(buf, "SUCCESS");
    } else if (type == FAIL) {
        strcpy(buf, "FAIL");
    } else {
        strcpy(buf, "INVALID");
    }
}
