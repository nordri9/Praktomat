#include "fms.h"

// Initialization of coordinates
const Coordinate coord_MUC_lat = {48, 21, 14};
const Coordinate coord_HAM_lat = {53, 37, 49};
const Coordinate coord_FRA_lat = {50, 1, 59};
const Coordinate coord_BER_lat = {52, 21, 44};
const Coordinate coord_DUS_lat = {51, 16, 51};
const Coordinate coord_CGN_lat = {50, 51, 57};
const Coordinate coord_STR_lat = {48, 41, 24};

const Coordinate coord_MUC_lon = {11, 47, 10};
const Coordinate coord_HAM_lon = {9, 59, 18};
const Coordinate coord_FRA_lon = {8, 34, 14};
const Coordinate coord_BER_lon = {13, 30, 2};
const Coordinate coord_DUS_lon = {6, 45, 26};
const Coordinate coord_CGN_lon = {7, 8, 34};
const Coordinate coord_STR_lon = {9, 13, 19};


// Initialization of airports
Airport airport_MUC = {"MUC", "EDDM", coord_MUC_lat, coord_MUC_lon, 453.0};
Airport airport_HAM = {"HAM", "EDDH", coord_HAM_lat, coord_HAM_lon, 16.0};
Airport airport_FRA = {"FRA", "EDDF", coord_FRA_lat, coord_FRA_lon, 111.0};
Airport airport_BER = {"BER", "EDDB", coord_BER_lat, coord_BER_lon, 48.0};
Airport airport_DUS = {"DUS", "EDDL", coord_DUS_lat, coord_DUS_lon, 45.0};
Airport airport_CGN = {"CGN", "EDDK", coord_CGN_lat, coord_CGN_lon, 92.0};
Airport airport_STR = {"STR", "EDDS", coord_STR_lat, coord_STR_lon, 389.0};

// Initialization of flight route
FlightPath flightPaths_LH2147[] = {
    {"LH 2147", &airport_MUC, &airport_HAM, {11, 30}, {14, 30}},
    {"LH 2147", &airport_HAM, &airport_FRA, {15, 30}, {16, 30}},
    {"LH 2147", &airport_FRA, &airport_MUC, {18, 30}, {20, 30}},
    {"LH 2147", &airport_MUC, &airport_HAM, {20, 45}, {22, 00}},
    {"LH 2147", &airport_HAM, &airport_MUC, {22, 30}, {23, 30}}
};

FlightPath flightPaths_EW5953[] = {
    {"EW 5953", &airport_MUC, &airport_DUS, {3, 00}, {04, 15}},
    {"EW 5953", &airport_DUS, &airport_BER, {8, 00}, {10, 00}},
    {"EW 5953", &airport_BER, &airport_CGN, {10, 12}, {13, 15}},
    {"EW 5953", &airport_CGN, &airport_MUC, {18, 00}, {20, 30}},
    {"EW 5953", &airport_MUC, &airport_DUS, {21,45}, {23,30}}
};

FlightPath flightPaths_X32174[] = {
    {"X3 2174", &airport_HAM, &airport_STR, {8, 00}, {10, 00}},
    {"X3 2174", &airport_STR, &airport_BER, {10, 15}, {13, 00}},
    {"X3 2174", &airport_BER, &airport_FRA, {13, 10}, {15, 00}},
    {"X3 2174", &airport_FRA, &airport_HAM, {15, 12}, {17, 00}},
    {"X3 2174", &airport_HAM, &airport_FRA, {22, 00}, {24, 00}}
};

// Initialization of airplanes
Airplane airplanes_Lufthansa[] = {
    {"A380", "D-AIMA", flightPaths_LH2147, 5}
};

Airplane airplanes_Eurowings[] = {
    {"A320", "D-AIAB", flightPaths_EW5953, 5}
};

Airplane airplanes_TUIFly[] = {
    {"B747", "D-ABCD", flightPaths_X32174, 5}
};

// Initialization of airlines
Airline airlines[] = {
    {"Lufthansa", airplanes_Lufthansa, 1},
    {"EuroWings", airplanes_Eurowings, 1},
    {"TUIFly", airplanes_TUIFly, 1}
};

/// Initialization of the flight management system
FMS fms = {airlines, 3};
