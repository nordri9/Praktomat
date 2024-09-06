// main.c
#include <stdio.h>
#include <stdlib.h>
#include "island.h"
#include "node.h"

void Setup_Island(Island * theIsland, char* name, int openHour, int openMinute, int closeHour, int closeMinute) {
    Time open = {openHour, openMinute};
    Time closed = {closeHour, closeMinute};
    Input_Island(theIsland, name, open, closed);
}

void Setup_Tour(Node **tour, Island *islands, int islandIndices[], int length) {
    // Create the first node manually
    *tour = Node_New();
    (*tour)->island = &islands[islandIndices[0]];
    
    Node *current = *tour;

    for (int i = 1; i < length; i++) {
        Node_Insert(current);  // Insert after current
        current = current->next;  // Move to the next node
        current->island = &islands[islandIndices[i]];
    }
}

void Output_Tour(Node *tour) {
    Node *current = tour;
    while (current != NULL) {
        Output_Island(current->island);
        current = current->next;
    }
}

int main() {
    Island islands[5];
    
    // Setup island data
    Setup_Island(&islands[0], "Amity Island", 9, 0, 17, 0);
    Setup_Island(&islands[1], "Craggy Island", 9, 0, 16, 0);
    Setup_Island(&islands[2], "Isla Nubar", 7, 0, 12, 0);
    Setup_Island(&islands[3], "Shutter Island", 8, 0, 20, 0);
    Setup_Island(&islands[4], "Skull Island", 8, 0, 17, 30);
    
    // Initialize tour lists
    Node *tour1 = NULL, *tour2 = NULL, *tour3 = NULL, *tour4 = NULL;
    
    int tour1_islands[] = {0, 1, 2, 0}; // Amity - Craggy - Isla Nubar - Amity
    int tour2_islands[] = {4, 1, 2, 4}; // Skull - Craggy - Isla Nubar - Skull
    int tour3_islands[] = {3, 4, 3};    // Shutter - Skull - Shutter
    int tour4_islands[] = {2, 4, 3, 0, 2}; // Isla Nubar - Skull - Shutter - Amity - Isla Nubar
    
    // Setup tours
    Setup_Tour(&tour1, islands, tour1_islands, 4);
    Setup_Tour(&tour2, islands, tour2_islands, 4);
    Setup_Tour(&tour3, islands, tour3_islands, 3);
    Setup_Tour(&tour4, islands, tour4_islands, 5);
    
    int tourNumber;
    do {
        printf("Please enter a tour number (1-4) or enter the number 0 to exit: ");
        scanf("%d", &tourNumber);

        switch (tourNumber) {
            case 1:
                Output_Tour(tour1);
                break;
            case 2:
                Output_Tour(tour2);
                break;
            case 3:
                Output_Tour(tour3);
                break;
            case 4:
                Output_Tour(tour4);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input, please enter a number between 0 and 4.\n");
        }
    } while (tourNumber != 0);

    return 0;
}
