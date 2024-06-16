#include "fms.h"
#include <stdio.h>
#include <stdlib.h>

Airport departureAirport = {
    .icao = "EDDF",
    .iata = "FRA",
    .latitude = {50, 2, 0},
    .longitude = {8, 34, 0},
    .heightAMSL = 364
};

Airport arrivalAirport = {
    .icao = "KLAX",
    .iata = "LAX",
    .latitude = {33, 56, 33},
    .longitude = {-118, 24, 29},
    .heightAMSL = 125
};

FlightPath flightPath = {
    .flightPathName = "LH 2147",
    .pDepartureAirport = &departureAirport,
    .pArrivalAirport = &arrivalAirport,
    .departure = {10, 0},
    .arrival = {14, 0}
};

Airplane airplane = {
    .airplaneName = "Boeing 747",
    .airVehicleRegestriation = "D-ABCD",
    .pFlightPath = &flightPath,
    .cntFlightPath = 1
};

Airline airline = {
    .airlineName = "Lufthansa",
    .pAirplane = &airplane,
    .cntAirplane = 1
};

FMS fms = {
    .pAirline = &airline,
    .cntAirline = 1
};