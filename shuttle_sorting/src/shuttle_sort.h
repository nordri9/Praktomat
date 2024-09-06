#ifndef shuttle_sort_H
#define shuttle_sort_H

// Definition of the Shuttle struct, representing each node in the doubly linked list
typedef struct Shuttle
{
    int mission_number;
    char start_date[11];
    char mission_designation[20];
    char orbiter[20];
    char launch_site[10];
    struct Shuttle *prev;  // Pointer to the previous node
    struct Shuttle *next;  // Pointer to the next node
} Shuttle;

// Function prototypes
Shuttle *load_shuttle_data(const char *filename);
void sort_shuttles(Shuttle **head);
void print_shuttles(Shuttle *head);
void free_shuttles(Shuttle *head);

#endif
