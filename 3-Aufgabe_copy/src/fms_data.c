#include <stdio.h>
#include "fms.h"

// Initialize airport data
Airport HAM = {"EDDH", "HAM", {53, 37, 49}, {9, 59, 18}, 16};
Airport MUC = {"EDDM", "MUC", {48, 21, 14}, {11, 47, 10}, 453};
Airport FRA = {"EDDF", "FRA", {50, 1, 59}, {8, 34, 14}, 111};
Airport DUS = {"EDDL", "DUS", {51, 16, 51}, {6, 45, 26}, 45};
Airport CGN = {"EDDK", "CGN", {50, 51, 57}, {7, 8, 34}, 92};
Airport BER = {"EDDB", "BER", {52, 21, 44}, {13, 30, 2}, 47};
Airport STR = {"EDDS", "STR", {48, 41, 24}, {9, 13, 19}, 389};

// Initialize flight path data
FlightPath LHPath1 = {"LH 2147", &MUC, &HAM, {11, 30}, {14, 30}};
FlightPath LHPath2 = {"LH 2147", &HAM, &FRA, {15, 30}, {16, 30}};
FlightPath LHPath3 = {"LH 2147", &FRA, &MUC, {18, 30}, {20, 30}};
FlightPath LHPath4 = {"LH 2147", &MUC, &HAM, {20, 45}, {22, 0}};
FlightPath LHPath5 = {"LH 2147", &HAM, &MUC, {22, 30}, {23, 30}};

FlightPath EWPath1 = {"EW 5953", &MUC, &DUS, {3, 0}, {4, 15}};
FlightPath EWPath2 = {"EW 5953", &DUS, &BER, {8, 0}, {10, 0}};
FlightPath EWPath3 = {"EW 5953", &BER, &CGN, {10, 12}, {13, 15}};
FlightPath EWPath4 = {"EW 5953", &CGN, &MUC, {18, 0}, {20, 30}};
FlightPath EWPath5 = {"EW 5953", &MUC, &DUS, {20, 45}, {23, 30}};

FlightPath X3Path1 = {"X3 2174", &HAM, &STR, {8, 0}, {10, 0}};
FlightPath X3Path2 = {"X3 2174", &STR, &BER, {10, 15}, {13, 0}};
FlightPath X3Path3 = {"X3 2174", &BER, &FRA, {13, 10}, {15, 0}};
FlightPath X3Path4 = {"X3 2174", &FRA, &HAM, {15, 12}, {17, 0}};
FlightPath X3Path5 = {"X3 2174", &HAM, &FRA, {22, 0}, {0, 0}};

//initialising the 3 airplanes 
Airplane LH2147={"A380","D-AIMA",.flightPaths={&LHPath1,&LHPath2,&LHPath3,&LHPath4,&LHPath5},5};

Airplane EW5953={"A320","D-AIAB",.flightPaths={&EWPath1,&EWPath2,&EWPath3,&EWPath4,&EWPath5},5};

Airplane X32174={"B747","D-ABCD",.flightPaths={&X3Path1,&X3Path2,&X3Path3,&X3Path4,&X3Path5},5};

//iniatialising the airlines
Airline LH={"Lufthansa",&LH2147,1};

Airline EW={"EuroWings",&EW5953,1};

Airline X3={"TUIFly",&X32174,1};

//iniatialising the FMS
FMS FMS1={.airlines={&LH,&EW,&X3},3};