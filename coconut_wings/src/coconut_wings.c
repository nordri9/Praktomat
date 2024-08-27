#include "coconut_wings.h"

// Create a new Island
Island* create_island(const char *name, const char *description, const char *opening_hours) {
    Island *new_island = (Island*)malloc(sizeof(Island));
    if (new_island == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    strcpy(new_island->name, name);
    strcpy(new_island->description, description);
    strcpy(new_island->opening_hours, opening_hours);
    new_island->prev = NULL;
    new_island->next = NULL;
    return new_island;
}

// Add an Island to a Tour
void add_island_to_tour(Tour *tour, Island *island) {
    if (tour->head == NULL) {
        tour->head = island;
        tour->tail = island;
    } else {
        tour->tail->next = island;
        island->prev = tour->tail;
        tour->tail = island;
    }
}

// Create a new Tour
Tour* create_tour() {
    Tour *new_tour = (Tour*)malloc(sizeof(Tour));
    if (new_tour == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_tour->head = NULL;
    new_tour->tail = NULL;
    return new_tour;
}

// Free the memory used by a Tour
void free_tour(Tour *tour) {
    Island *current = tour->head;
    while (current != NULL) {
        Island *next = current->next;
        free(current);
        current = next;
    }
    free(tour);
}

// Print the information about a Tour
void print_tour(const Tour *tour, int tour_number) {
    printf("---------------------------------------------------\n");
    printf("---------------- Tour %d ---------------------------\n", tour_number);
    printf("---------------------------------------------------\n");

    Island *current = tour->head;
    while (current != NULL) {
        printf("---------------------------------------------------\n");
        printf("Island : %s\n", current->name);
        printf("Opening hours: %s\n", current->opening_hours);
        current = current->next;
    }

    printf("---------------------------------------------------\n");
    printf("End\n");
}

// Initialize a specific Tour based on the tour number
Tour* initialize_tour(int tour_number) {
    Tour *tour = create_tour();

    switch (tour_number) {
        case 1:
            add_island_to_tour(tour, create_island("Amity Island", "Idyllic vacation island with diverse marine life.", "09:00 - 17:00"));
            add_island_to_tour(tour, create_island("Craggy Island", "Remote island known for its scenic church.", "09:00 - 16:00"));
            add_island_to_tour(tour, create_island("Isla Nubar", "Unique natural monument with a world-famous park.", "07:00 - 12:00"));
            add_island_to_tour(tour, create_island("Amity Island", "Idyllic vacation island with diverse marine life.", "09:00 - 17:00"));
            break;
        case 2:
            add_island_to_tour(tour, create_island("Skull Island", "Tropical island with unique wildlife.", "08:00 - 17:30"));
            add_island_to_tour(tour, create_island("Craggy Island", "Remote island known for its scenic church.", "09:00 - 16:00"));
            add_island_to_tour(tour, create_island("Isla Nubar", "Unique natural monument with a world-famous park.", "07:00 - 12:00"));
            add_island_to_tour(tour, create_island("Skull Island", "Tropical island with unique wildlife.", "08:00 - 17:30"));
            break;
        case 3:
            add_island_to_tour(tour, create_island("Shutter Island", "Island with an abandoned asylum.", "08:00 - 20:00"));
            add_island_to_tour(tour, create_island("Skull Island", "Tropical island with unique wildlife.", "08:00 - 17:30"));
            add_island_to_tour(tour, create_island("Shutter Island", "Island with an abandoned asylum.", "08:00 - 20:00"));
            break;
        case 4:
            add_island_to_tour(tour, create_island("Isla Nubar", "Unique natural monument with a world-famous park.", "07:00 - 12:00"));
            add_island_to_tour(tour, create_island("Skull Island", "Tropical island with unique wildlife.", "08:00 - 17:30"));
            add_island_to_tour(tour, create_island("Shutter Island", "Island with an abandoned asylum.", "08:00 - 20:00"));
            add_island_to_tour(tour, create_island("Amity Island", "Idyllic vacation island with diverse marine life.", "09:00 - 17:00"));
            add_island_to_tour(tour, create_island("Isla Nubar", "Unique natural monument with a world-famous park.", "07:00 - 12:00"));
            break;
        default:
            free_tour(tour);
            return NULL;
    }

    return tour;
}
