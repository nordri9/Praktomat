#ifndef shuttle_sort_H
#define shuttle_sort_H

typedef struct Shuttle
{
    int mission_number;
    char start_date[11]; // Format: DD.MM.YYYY
    char mission_designation[20];
    char orbiter[20];
    char launch_site[10];
    struct Shuttle *prev;
    struct Shuttle *next;
} Shuttle;

// Function prototypes
Shuttle *load_shuttle_data(const char *filename);
void sort_shuttles(Shuttle **head);
void print_shuttles(Shuttle *head);
void free_shuttles(Shuttle *head);

#endif // shuttle_sort_H
