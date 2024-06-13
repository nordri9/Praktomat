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

    FlightPath MUC_HAM1, HAM_FRA1, FRA_HUC, MUC_HAM2, HAM_MUC, MUC_DUS1, DUS_BER, BER_CGN, CGN_MUC, MUC_DUS2, HAM_STR, STR_BER, BER_FRA, FRA_HAM, HAM_FRA2;

    initFlightPath(&MUC_HAM1, "muc_ham1", &munich, &hamburg, t1130.hour, t1130.minute, t1430.hour, t1430.minute);
    initFlightPath(&HAM_FRA1, "ham_fra1", &hamburg, &frankfurt, t1530.hour, t1530.minute, t1630.hour, t1630.minute);
    initFlightPath(&FRA_HUC, "fra_huc", &frankfurt, &munich, t1830.hour, t1830.minute, t2030.hour, t2030.minute);
    initFlightPath(&MUC_HAM2, "muc_ham2", &munich, &hamburg, t2045.hour, t2045.minute, t2200.hour, t2200.minute);
    initFlightPath(&HAM_MUC, "ham_muc", &hamburg, &munich, t2230.hour, t2230.minute, t2330.hour, t2330.minute);
    initFlightPath(&MUC_DUS1, "muc_dus1", &munich, &dusseldorf, t0300.hour, t0300.minute, t0415.hour, t0415.minute);
    initFlightPath(&DUS_BER, "dus_ber", &dusseldorf, &berlin, t0800.hour, t0800.minute, t1000.hour, t1000.minute);
    initFlightPath(&BER_CGN, "ber_cgn", &berlin, &cologne, t1012.hour, t1012.minute, t1015.hour, t1015.minute);
    initFlightPath(&CGN_MUC, "cgn_muc", &cologne, &munich, t1800.hour, t1800.minute, t2030.hour, t2030.minute);
    initFlightPath(&MUC_DUS2, "muc_dus2", &munich, &dusseldorf, t2145.hour, t2145.minute, t2330.hour, t2330.minute);
    initFlightPath(&HAM_STR, "ham_str", &hamburg, &stuttgart, t0800.hour, t0800.minute, t1512.hour, t1512.minute);
    initFlightPath(&STR_BER, "str_ber", &stuttgart, &berlin, t1015.hour, t1015.minute, t1300.hour, t1300.minute);
    initFlightPath(&BER_FRA, "ber_fra", &berlin, &frankfurt, t1310.hour, t1310.minute, t1500.hour, t1500.minute);
    initFlightPath(&FRA_HAM, "fra_ham", &frankfurt, &hamburg, t1512.hour, t1512.minute, t1700.hour, t1700.minute);
    initFlightPath(&HAM_FRA2, "ham_fra2", &hamburg, &frankfurt, t2200.hour, t2200.minute, t2400.hour, t2400.minute);

    Airplane a380, a320, b747;

    FlightPath a380_flightpaths[] = {MUC_HAM1, HAM_FRA1, FRA_HUC, MUC_HAM2, HAM_MUC};
    FlightPath a320_flightpaths[] = {MUC_DUS1, DUS_BER, BER_CGN, CGN_MUC, MUC_DUS2};
    FlightPath b747_flightpaths[] = {HAM_STR, STR_BER, BER_FRA, FRA_HAM, HAM_FRA2};

    initAirplane(&a380, "A380", "D-AIMA", &a380_flightpaths[0], sizeof(a380_flightpaths) / sizeof(a380_flightpaths[0]));
    initAirplane(&a320, "A320", "D-AIMA", &a320_flightpaths[0], sizeof(a320_flightpaths) / sizeof(a320_flightpaths[0]));
    initAirplane(&b747, "B747", "D-AIMA", &b747_flightpaths[0], sizeof(b747_flightpaths) / sizeof(b747_flightpaths[0]));

    //   printAirplane(&a380);
    Airline Lufthansa, EuroWings, TUIfly;

    initAirline(&Lufthansa, "Lufthansa", &a380, 1);
    initAirline(&EuroWings, "EuroWings", &a320, 2);
    initAirline(&TUIfly, "   TUIfly", &b747, 3);

    // printAirline(&Lufthansa);
    FMS section1, section2, section3;
    initFMS(&section1, &Lufthansa, 1);
    initFMS(&section2, &EuroWings, 1);

    initFMS(&section3, &TUIfly, 1);

    // Generate and print the time table
    Generate_Time_Table(&section1);

    return 0;
}