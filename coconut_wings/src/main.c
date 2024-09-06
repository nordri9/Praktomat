#include <stdio.h>
#include <stdlib.h>
#include "island.h"
#include "node.h"

// Function to set up an island
void Setup_Island(Island *island, char* name, int openHour, int openMinute, int closeHour, int closeMinute) {
    Input_Island(island, name, openHour, openMinute, closeHour, closeMinute);
}

// Function to set up a tour
void Setup_Tour(Node **tour, Island *island) {
    Node *newNode = Node_New();
    newNode->island = island;
    if (*tour == NULL) {
        *tour = newNode;  // Set head if list is empty
    } else {
        Node_Insert(*tour, newNode);
    }
}

int main() {
    Island amity, craggy, islaNubar, shutter, skull;

    // Set up islands
    Setup_Island(&amity, "Amity", 9, 0, 17, 0);
    Setup_Island(&craggy, "Craggy", 9, 0, 16, 0);
    Setup_Island(&islaNubar, "Isla Nubar", 7, 0, 12, 0);
    Setup_Island(&shutter, "Shutter", 8, 0, 20, 0);
    Setup_Island(&skull, "Skull", 8, 0, 17, 30);

    // Set up tours
    Node *tour1 = NULL, *tour2 = NULL, *tour3 = NULL, *tour4 = NULL;
    Setup_Tour(&tour1, &amity);
    Setup_Tour(&tour1, &craggy);
    Setup_Tour(&tour1, &islaNubar);
    Setup_Tour(&tour1, &amity);

    Setup_Tour(&tour2, &skull);
    Setup_Tour(&tour2, &craggy);
    Setup_Tour(&tour2, &islaNubar);
    Setup_Tour(&tour2, &skull);

    Setup_Tour(&tour3, &shutter);
    Setup_Tour(&tour3, &skull);
    Setup_Tour(&tour3, &shutter);

    Setup_Tour(&tour4, &islaNubar);
    Setup_Tour(&tour4, &skull);
    Setup_Tour(&tour4, &shutter);
    Setup_Tour(&tour4, &amity);
    Setup_Tour(&tour4, &islaNubar);

    int tourNumber;
    while (1) {
        printf("Please enter a tour number (1-4) or enter 0 to exit: ");
        scanf("%d", &tourNumber);

        if (tourNumber == 0) {
            break;
        }

        printf("---------------------------------------------------\n");
        printf("---------------- Tour %d ---------------------------\n", tourNumber);
        printf("---------------------------------------------------\n");

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
            default:
                printf("Invalid tour number!\n");
        }
    }

    return 0;
}
