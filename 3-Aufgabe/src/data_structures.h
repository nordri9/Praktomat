// data_structures.h
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// data_structure.h
#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

typedef struct Coordinate {
    double degree;
    double minute;
    double second;
} Coordinate;

typedef struct Airport {
    char icao[4];
    char iata[3];
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
} Airport;

// ... Define other structures (Time, FlightPath, Airplane, Airline, FMS) here



#endif