#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#define MAX_STR 20

// Structs done like in the datastructure
typedef struct coordinate{
    double degree;
    double minute;
    double second;
}Coordinate;

typedef struct time{
   unsigned char hour;
   unsigned char minute; 
}Time;

typedef struct airport{
    char icao[MAX_STR];
    char iata[MAX_STR];
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
}Airport;

typedef struct flightPath {
    char flightPathName[MAX_STR];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
    }FlightPath;

typedef struct airplane{
    char airplaneName[ MAX_STR ];
    char airVehicleRegestriation[MAX_STR];
    FlightPath* pFlightPath[5];        //using an array to point out the different paths
    unsigned int cntFlightPath;
}Airplane;
typedef struct airline{
    char airlineName[MAX_STR];
    Airplane *pAirplane;    //arrays could be used aswell to facilitate multiple planes per airline
    unsigned int cntAirplane;

}Airline;
typedef struct fms{
    Airline *pAirline[3];    //using an array for the three different airlines
    unsigned int cntAirline;
}FMS;


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