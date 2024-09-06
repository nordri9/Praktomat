// island.h
#ifndef ISLAND_H_
#define ISLAND_H_

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[50];
    Time open;
    Time closed;
} Island;

void Input_Island(Island * theIsland, char* name, Time open, Time closed);
void Output_Island(Island * theIsland);

#endif /* ISLAND_H_ */
