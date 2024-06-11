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

    Time t0300, t0415, t0800, t1000, t1012, t1015, t1130, t1300, t1310, t1315, t1430, t1500, t1512, t1530, t1630, t1700, t1800, t1830, t2030, t2045, t2145, t2200, t2230, t2330, t2400;

    initTime(&t0300, 3, 0);
    initTime(&t0415, 4, 15);
    initTime(&t0800, 8, 0);
    initTime(&t1000, 10, 0);
    initTime(&t1012, 10, 12);
    initTime(&t1015, 10, 15);
    initTime(&t1130, 11, 30);
    initTime(&t1300, 13, 0);
    initTime(&t1310, 13, 10);
    initTime(&t1315, 13, 15);
    initTime(&t1430, 14, 30);
    initTime(&t1500, 15, 0);
    initTime(&t1512, 15, 12);
    initTime(&t1530, 15, 30);
    initTime(&t1630, 16, 30);
    initTime(&t1700, 17, 0);
    initTime(&t1800, 18, 0);
    initTime(&t1830, 18, 30);
    initTime(&t2030, 20, 30);
    initTime(&t2045, 20, 45);
    initTime(&t2145, 21, 45);
    initTime(&t2200, 22, 0);
    initTime(&t2230, 22, 30);
    initTime(&t2330, 23, 30);
    initTime(&t2400, 24, 0);

    printTime(&t1015);

    FlightPath  HAM_FRA, FRA_HUC, HAM_MUC, MUC_DUS, DUS_BER, BER_CGN, CGN_MUC, HAM_STR, STR_BER, BER_FRA, FRA_HAM;
    initFlightPath(&HAM_FRA, "ham_fra", &hamburg, &frankfurt, t1530.hour, t1530.minute, t1630.hour, t1630.minute);
    initFlightPath(&FRA_HUC, "fra_huc", &frankfurt, &munich, t1830.hour, t1830.minute, t2030.hour, t2030.minute);
    initFlightPath(&HAM_MUC, "ham_muc", &hamburg, &munich, t2230.hour, t2230.minute, t2330.hour, t2330.minute);
    initFlightPath(&MUC_DUS, "muc_dus", &munich, &dusseldorf, t0300.hour, t0300.minute, t0415.hour, t0415.minute);
    initFlightPath(&DUS_BER, "dus_ber", &dusseldorf, &berlin, t0800.hour, t0800.minute, t1000.hour, t1000.minute);
    initFlightPath(&BER_CGN, "ber_cgn", &berlin, &cologne, t1012.hour, t1012.minute, t1015.hour, t1015.minute);
    initFlightPath(&CGN_MUC, "cgn_muc", &cologne, &munich, t1300.hour, t1300.minute, t1310.hour, t1310.minute);
    initFlightPath(&MUC_DUS, "muc_dus", &munich, &dusseldorf, t2145.hour, t2145.minute, t2330.hour, t2330.minute);
    initFlightPath(&HAM_STR, "ham_str", &hamburg, &stuttgart, t1500.hour, t1500.minute, t1512.hour, t1512.minute);
    initFlightPath(&STR_BER, "str_ber", &stuttgart, &berlin, t1530.hour, t1530.minute, t1630.hour, t1630.minute);
    initFlightPath(&BER_FRA, "ber_fra", &berlin, &frankfurt, t1700.hour, t1700.minute, t1800.hour, t1800.minute);
    initFlightPath(&FRA_HAM, "fra_ham", &frankfurt, &hamburg, t1512.hour, t1512.minute, t1700.hour, t1700.minute);
    initFlightPath(&HAM_STR, "ham_fra", &hamburg, &frankfurt, t2200.hour, t2230.minute, t2400.hour, t2400.minute);



for (int i = 0; i < 2;++i){
    FlightPath MUC_HAM[i];
initFlightPath ()
}
    /*08
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