#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct Coordinate
{
    double degree;
    double minute;
    double second;
} Coordinate;

typedef struct Airport
{
    char icao[5];
    char iata[4];
    struct Coordinate latitude;
    struct Coordinate longitude;
    float heightAMSL;
} Airport;

typedef struct Time
{
    unsigned char hour;
    unsigned char minute;
} Time;

typedef struct FlightPath {
    char flightPathName[32];
    struct Airport *pDepartureAirport;
    struct Airport *pArrivalAirport;
    struct Time departure;
    struct Time arrival;
}FlightPath;

typedef struct Airplane {
    char airplaneName[32];
    char airVehicleRegestriation[32];
    struct FlightPath *pFlightPath;
    unsigned int cntFlightPath;
}Airplane;

typedef struct Airline {
    char airlineName[32];
    struct Airplane *pAirplane;
    unsigned int cntAirplane;
}Airline;

typedef struct FMS {
    struct Airline *pAirline;
    unsigned int cntAirline;
}FMS;


void initCoordinate(Coordinate *c, double degree, double minute, double second);
void initAirport(Airport *a, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL);
void initTime(Time *t, unsigned char hour, unsigned char minute);
void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *pArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute);
void initAirplane(Airplane *aplane, char *airplaneName, char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath);
void initAirline(Airline *al, char *airlineName, Airplane *pAirplane, unsigned int cntAirplane);
void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline);


void printCoordinate(Coordinate *c);
void printTime(Time *t);
void printAirport(Airport *a);
void printFlightPath(FlightPath *fp);
void printAirplane(Airplane *aplane);
void printAirline(Airline *al);
void Generate_Time_Table(FMS *pFMS);

int datatest();
#endif