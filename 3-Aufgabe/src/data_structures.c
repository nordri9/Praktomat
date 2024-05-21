#include "fms.h"
#include <math.h>
#include <stdio.h>

int data() {

struct Coordinate {
    double degree;
    double minute;
    double second;
};

struct Airport {
    char icao[4];
    char iata[3];
    struct Coordinate latitude;
    struct Coordinate longitude;
    float heightAMSL;
};

struct Time {
    unsigned char hour;
    unsigned char minute;
};

struct FlightPath {
    char flightPathName[32];
    struct Airport *pDepartureAirport;
    struct Airport *pArrivalAirport;
    struct Time departure;
    struct Time arrival;
};

struct Airplane {
    char airplaneName[32];
    char airVehicleRegestriation[16];
    struct FlightPath *pFlightPath;
    unsigned int cntFlightPath;
};

struct Airline {
    char airlineName[32];
    struct Airplane *pAirplane;
    unsigned int cntAirplane;
};

struct FMS {
    struct Airline *pAirline;
    unsigned int cntAirline;
};


  return 0;
}