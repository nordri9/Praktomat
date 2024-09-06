#ifndef ISLAND_H_
#define ISLAND_H_

typedef struct {
    char name[50];
    int openHour;
    int openMinute;
    int closeHour;
    int closeMinute;
} Island;

void Input_Island(Island *theIsland, char* name, int openHour, int openMinute, int closeHour, int closeMinute);
void Output_Island(Island* theIsland);

#endif /* ISLAND_H_ */
