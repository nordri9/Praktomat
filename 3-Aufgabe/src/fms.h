#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct
{
    double degree;
    double minute;
    double second;
} Coordinate;

typedef struct
{
    char icao[5]; // 4 characters + null terminator
    char iata[4]; // 3 characters + null terminator
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
} Airport;

typedef struct
{
    unsigned char hour;
    unsigned char minute;
} Time;

typedef struct
{
    char flightPathName[32];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
} FlightPath;

typedef struct
{
    char airplaneName[32];
    char airVehicleRegestriation[32];
    FlightPath *pFlightPath;
    unsigned int cntFlightPath;
} Airplane;

typedef struct
{
    char airlineName[32];
    Airplane *pAirplane;
    unsigned int cntAirplane;
} Airline;

typedef struct
{
    Airline *pAirline;
    unsigned int cntAirline;
} FMS;


void fms_data_input();

void initCoordinate(Coordinate *c, double degree, double minute, double second);
void initAirport(Airport *a, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL);
void initTime(Time *t, unsigned char hour, unsigned char minute);
void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *pArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute);
void initAirplane(Airplane *aplane, const char *airplaneName, const char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath);
void initAirline(Airline *al, const char *airlineName, Airplane *pAirplane, unsigned int cntAirplane);
void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline);

void printCoordinate(Coordinate *c);
void printDepartureTime(Time *t);
void printArrivalTime(Time *t);

double calculateDegree(double degrees, double minutes, double seconds);
double sinDeg(double degrees);
double cosDeg(double degrees);
double calculate_distance(Airport *DepartureAirport, Airport *ArrivalAirport);
void printDistance(Airport *DepartureAirport, Airport *ArrivalAirport);

void printAirport(Airport *a);
void printFlightPath(FlightPath *fp, unsigned char table_type);
void printAirplane(Airplane *aplane, char airlineName[32], unsigned char table_type, unsigned int cntAirline);
void printAirline(Airline *al, unsigned char table_type, unsigned int cntAirline);

void Generate_Time_Table(FMS *pFMS);
void Generate_Distance_Table(FMS *pFMS);
void Generate_Duration_Table(FMS *pFMS);

#endif