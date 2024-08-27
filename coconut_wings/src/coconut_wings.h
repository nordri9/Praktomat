#ifndef COCONUT_WINGS_H
#define COCONUT_WINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an Island
typedef struct Island {
    char name[50];
    char description[256];
    char opening_hours[20];
    struct Island *prev;
    struct Island *next;
} Island;

// Define the structure for a Tour (a doubly linked list of Islands)
typedef struct Tour {
    Island *head;
    Island *tail;
} Tour;

// Function prototypes
Island* create_island(const char *name, const char *description, const char *opening_hours);
void add_island_to_tour(Tour *tour, Island *island);
Tour* create_tour();
void free_tour(Tour *tour);
void print_tour(const Tour *tour, int tour_number);

Tour* initialize_tour(int tour_number);
void initialize_all_tours();

#endif // COCONUT_WINGS_H
