#ifndef FMS_H
#define FMS_H

// Structure to represent coordinates in degrees, minutes, and seconds
typedef struct
{
    double degree;
    double minute;
    double second;
} Coordinate;

// Structure to represent time with hour and minute
typedef struct
{
    unsigned char hour;
    unsigned char minute;
} Time;

// Structure to represent an airport with ICAO and IATA codes, coordinates, and height above mean sea level
typedef struct
{
    char icao[5];
    char iata[4];
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
} Airport;

// Structure to represent a flight path including departure and arrival airports and times
typedef struct
{
    char flightPathName[10];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
} FlightPath;

// Structure to represent an airplane with a name, registration, and flight paths
typedef struct
{
    char airplaneName[50];
    char airVehicleRegistration[10];
    FlightPath *pFlightPath;
    unsigned int cntFlightPath;
} Airplane;

// Structure to represent an airline with a name and a list of airplanes
typedef struct
{
    char airlineName[50];
    Airplane *pAirplane;
    unsigned int cntAirplane;
} Airline;

// Structure to represent the Flight Management System (FMS) containing airlines
typedef struct
{
    Airline *pAirline;
    unsigned int cntAirline;
} FMS;

// Function declarations for generating tables and calculating distances
void Generate_Time_Table(FMS *pFMS);
void Generate_Duration_Table(FMS *pFMS);
void Generate_Distance_Table(FMS *pFMS);
double Calculate_Route_Distance(FMS *pFMS, const char *from, const char *to);
double Calculate_Distance(double lat1, double lon1, double lat2, double lon2);
double Degrees_To_Radians(double degrees);
double Sin_Deg(double degrees);
double Cos_Deg(double degrees);

#endif // FMS_H
