#ifndef FMS_H_
#define FMS_H_
#define MAX_STR 20

// Structs done like in the datastructure
typedef struct coordinate{
    double degree;
    double minute;
    double second;
}Coordinate;

typedef struct time{
   unsigned char hour;
   unsigned char min; 
}Time;

typedef struct airport{
    char icao[MAX_STR];
    char iata[MAX_STR];
    Coordinate *Latitude;
    Coordinate *Longitude;
    float heightAMSL;
}Airport;

typedef struct flightPath {
    char flightPathName[MAX_STR];
    Airport *pDepatureAirport;
    Airport *pArrivalAirport;
    Time *pdepature;
    Time *parrival;
    }FlightPath;

typedef struct airplane{
    char airplanename[ MAX_STR ];
    char airVehicleRegistration[MAX_STR];
    FlightPath* flightPaths[5];        //using an array to point out the different paths
    unsigned int cntFlightPaths;
}Airplane;
typedef struct airline{
    char airlineName[MAX_STR];
    Airplane *pairplane;    //arrays could be used aswell to facilitate multiple planes per airline
    unsigned int cntAirplane;

}Airline;
typedef struct fms{
    Airline *airlines[3];    //using an array for the three different airlines
    unsigned int cntAirline;
   ;
}FMS;




void Generate_Time_Table(FMS * pFMS);
void Generate_Duration_Table(FMS * pFMS);
void Generate_Distance_Table(FMS * pFMS);


#endif //FMS_H_

