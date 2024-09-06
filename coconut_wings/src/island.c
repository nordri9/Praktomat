#include <stdio.h>
#include <string.h>
#include "island.h"

void Input_Island(Island *theIsland, char* name, int openHour, int openMinute, int closeHour, int closeMinute) {
    strcpy(theIsland->name, name);
    theIsland->openHour = openHour;
    theIsland->openMinute = openMinute;
    theIsland->closeHour = closeHour;
    theIsland->closeMinute = closeMinute;
}

void Output_Island(Island *theIsland) {
    printf("---------------------------------------------------\n");
    printf("Island : %s\n", theIsland->name);
    printf("Opening hours: %02d:%02d - %02d:%02d\n", theIsland->openHour, theIsland->openMinute, theIsland->closeHour, theIsland->closeMinute);
    printf("---------------------------------------------------\n");
}
