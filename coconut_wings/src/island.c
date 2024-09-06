// island.c
#include <stdio.h>
#include <string.h>
#include "island.h"

void Input_Island(Island * theIsland, char* name, Time open, Time closed) {
    strcpy(theIsland->name, name);
    theIsland->open = open;
    theIsland->closed = closed;
}

void Output_Island(Island * theIsland) {
    printf("---------------------------------------------------\n");
    printf("Island: %s\n", theIsland->name);
    printf("Opening hours: %02d:%02d - %02d:%02d\n", theIsland->open.hour, theIsland->open.minute, theIsland->closed.hour, theIsland->closed.minute);
    printf("---------------------------------------------------\n");
}
