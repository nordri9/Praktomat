#include "data_structures.h"
#include "fms_data.h"
#include "fms.h"
#include <stdio.h>
#include <stdlib.h>

int fms_data_input()
{

    Airport hamburg, berlin, dusseldorf, cologne, frankfurt, stuttgart, munich;

    initAirport(&hamburg, "EDDH", "HAM", 53, 37, 49, 9, 59, 18, 16);
    initAirport(&berlin, "EDDB", "BER", 52, 21, 14, 13, 30, 2, 48);
    initAirport(&dusseldorf, "EDDL", "DUS", 51, 16, 51, 6, 45, 26, 45);
    initAirport(&cologne, "EDDK", "CGN", 50, 51, 57, 7, 8, 34, 92);
    initAirport(&frankfurt, "EDDF", "FRA", 50, 1, 59, 8, 34, 14, 111);
    initAirport(&stuttgart, "EDDS", "STR", 48, 41, 23, 9, 13, 18, 389);
    initAirport(&munich, "EDDM", "MUC", 48, 21, 14, 11, 47, 10, 453);

    Time testtime;

    initTime(&testtime, 13, 30);
    printTime(&testtime);

    FlightPath MUC_HAM, HAM_FRA, FRA_HUC, MUC_HAM, MUC_DUS, DUS_BER, BER_CGN, CGN_MUC, HAM_STR, STR_BER, BER_FRA, FRA_HAM;
    initFlightPath(&MUC_HAM, "muc_ham", &munich, &hamburg, testtime.hour, testtime.minute, testtime.hour, testtime.minute);
    
    
     /*
         // Array of airport pointers
         Airport *airports[] = {&hamburg, &berlin, &dusseldorf, &cologne, &frankfurt, &stuttgart, &munich};
         size_t numAirports = sizeof(airports) / sizeof(airports[0]);

         // Calculate the total number of flight paths
         size_t numFlightPaths = numAirports * (numAirports - 1);

         // Allocate memory for flight paths
         FlightPath *flightPaths = (FlightPath *)malloc(numFlightPaths * sizeof(FlightPath));
         if (flightPaths == NULL)
         {
             fprintf(stderr, "Memory allocation failed\n");
             return 1;
         }

         // Initialize flight paths
         size_t index = 0;
         for (size_t i = 0; i < numAirports; ++i)
         {
             for (size_t j = 0; j < numAirports; ++j)
             {
                 if (i != j)
                 {
                     char flightPathName[32];
                     snprintf(flightPathName, 32, "%s-%s", airports[i]->iata, airports[j]->iata);
                     printf("Pfad: %s\n", flightPathName);                                                       // Correct way to use printf                initFlightPath(&flightPaths[index], flightPathName, airports[i], airports[j], 8, 0, 10, 0); // Example times
                     initFlightPath(&flightPaths[index], flightPathName, airports[i], airports[j], 8, 0, 10, 0); // Example times
                     index++;
                 }
             }
         }

         // printFlightPaths(flightPaths, numFlightPaths);

         Airplane a380, a320, b747;
         initAirplane(&a380, "D-AIMA")


         Airline lufthansa, eurowings, tuifly;

         initAirplane(&lufthansa)


         • Lufthansa
         • EuroWings
         • TUIfly


             // Print all airport information
             printAirport(&hamburg);
             printAirport(&berlin);
             printAirport(&dusseldorf);
             printAirport(&cologne);
             printAirport(&frankfurt);
             printAirport(&stuttgart);
             printAirport(&munich);


     free(flightPaths);
   */

    printf("data input\n");

    return 0;
}