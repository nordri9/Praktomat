#include <stdio.h>
#include <math.h>
#include <string.h>
#include "fms.h"

// Function to generate and print the flight timetable
void Generate_Time_Table(FMS *pFMS) {
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");

    // Loop through all airlines, airplanes of airlines and flight paths of airplanes
    for (unsigned int i = 0; i < pFMS->cntAirline; ++i) {
        Airline *airline = &pFMS->pAirline[i];
        for (unsigned int j = 0; j < airline->cntAirplane; ++j) {
            Airplane *airplane = &airline->pAirplane[j];
            for (unsigned int k = 0; k < airplane->cntFlightPath; ++k) {
                FlightPath *flightPath = &airplane->pFlightPath[k];

                // Print the flight details
                printf("%10s|%10s|%4s|%4s|    %02d:%02d|   %02d:%02d|  %6s\n",
                       airline->airlineName,
                       flightPath->flightPathName,
                       flightPath->pDepartureAirport->icao,
                       flightPath->pArrivalAirport->icao,
                       flightPath->departure.hour,
                       flightPath->departure.minute,
                       flightPath->arrival.hour,
                       flightPath->arrival.minute,
                       airplane->airVehicleRegistration);
            }
        }
    }

    printf("\n");
}


// Function to generate the duration table
void Generate_Duration_Table(FMS *pFMS) {
    // Loop through all airlines, airplanes of airlines and flight paths of airplanes
    for (unsigned int i = 0; i < pFMS->cntAirline; ++i) {
        Airline *airline = &pFMS->pAirline[i];
        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");
        for (unsigned int j = 0; j < airline->cntAirplane; ++j) {
            Airplane *airplane = &airline->pAirplane[j];
            double totalDuration = 0.0;
            for (unsigned int k = 0; k < airplane->cntFlightPath; ++k) {
                FlightPath *flightPath = &airplane->pFlightPath[k];

                /* Calculate departure and arrival times in minutes, 
                calculate the duration of the flight in minutes and convert duration to hours and minutes */
                int departureMinutes = flightPath->departure.hour * 60 + flightPath->departure.minute;
                int arrivalMinutes = flightPath->arrival.hour * 60 + flightPath->arrival.minute;

                int durationMinutes = arrivalMinutes - departureMinutes;

                int hours = durationMinutes / 60;
                int minutes = durationMinutes % 60;

                // Print the flight duration details
                printf("%10s|%10s|%4s|%4s|  %02d:%02d\n",
                       airline->airlineName,
                       flightPath->flightPathName,
                       flightPath->pDepartureAirport->icao,
                       flightPath->pArrivalAirport->icao,
                       hours, minutes);

                // Add the flight duration to the total duration
                totalDuration += durationMinutes;
            }

            // Output total flight time for the aircraft model
            int totalHours = (int)totalDuration / 60;
            int totalMinutes = (int)totalDuration % 60;
            printf("\n");
            printf("Total flight Time for %s %s is %02d:%02d\n\n", airline->airlineName, airplane->airplaneName, totalHours, totalMinutes);
        }
    }
}


// Function to generate the distance table
void Generate_Distance_Table(FMS *pFMS) {
    // Loop through all airlines, airplanes of airlines and flight paths of airplanes
    for (unsigned int i = 0; i < pFMS->cntAirline; ++i) {
        Airline *airline = &pFMS->pAirline[i];
        double totalDistance = 0.0; 
        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");
        for (unsigned int j = 0; j < airline->cntAirplane; ++j) {
            Airplane *airplane = &airline->pAirplane[j];
            for (unsigned int k = 0; k < airplane->cntFlightPath; ++k) {
                FlightPath *flightPath = &airplane->pFlightPath[k];
                
                // Calculate the distance between departure and arrival airports
                double distance = Calculate_Route_Distance(pFMS, flightPath->pDepartureAirport->iata, flightPath->pArrivalAirport->iata);

                // Print the flight distance details
                printf("%10s|%10s|%4s|%4s|%7.2f\n",
                       airline->airlineName,
                       flightPath->flightPathName,
                       flightPath->pDepartureAirport->icao,
                       flightPath->pArrivalAirport->icao,
                       distance);

                // Add the flight distance to the total distance
                totalDistance += distance;
            }
        }

        // Output total flight distance for the airline
        printf("\n");
        printf("Total flight distance for %s %s is %.2f\n\n", airline->airlineName, airline->pAirplane[0].airplaneName, totalDistance);
    }
}


// Function to calculate the distance between two airports
double Calculate_Route_Distance(FMS *pFMS, const char* from, const char* to) {
    Airport* airport_from = NULL;
    Airport* airport_to = NULL;

    // Loop through all airlines, airplanes of airlines and flight paths of airplanes
    for (unsigned int i = 0; i < pFMS->cntAirline; ++i) {
        Airline *airline = &pFMS->pAirline[i];
        for (unsigned int j = 0; j < airline->cntAirplane; ++j) {
            Airplane *airplane = &airline->pAirplane[j];
            for (unsigned int k = 0; k < airplane->cntFlightPath; ++k) {
                FlightPath *path = &airplane->pFlightPath[k];

                // Check if the departure airport matches the 'from' airport
                if (strcmp(path->pDepartureAirport->iata, from) == 0) {
                    airport_from = path->pDepartureAirport;
                }
                // Check if the arrival airport matches the 'to' airport
                if (strcmp(path->pArrivalAirport->iata, to) == 0) {
                    airport_to = path->pArrivalAirport;
                }
            }
        }
    }

    // Calculate the distance if both airports were found
    if (airport_from && airport_to) {
        return Calculate_Distance(
            airport_from->latitude.degree + airport_from->latitude.minute / 60.0 + airport_from->latitude.second / 3600.0,
            airport_from->longitude.degree + airport_from->longitude.minute / 60.0 + airport_from->longitude.second / 3600.0,
            airport_to->latitude.degree + airport_to->latitude.minute / 60.0 + airport_to->latitude.second / 3600.0,
            airport_to->longitude.degree + airport_to->longitude.minute / 60.0 + airport_to->longitude.second / 3600.0
        );
    }
    // If either of the airports was not found, return 0.0
    return 0.0;
}


// Function to calculate the distance between two geographic coordinates
double Calculate_Distance(double lat1, double lon1, double lat2, double lon2) {
    double r = 6378.388; // Earth's radius in km
    return r * acos(Sin_Deg(lat1) * Sin_Deg(lat2) + Cos_Deg(lat1) * Cos_Deg(lat2) * Cos_Deg(lon1 - lon2));
}

// Function to convert degrees to radians
double Degrees_To_Radians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate sine of an angle in degrees
double Sin_Deg(double degrees) {
    return sin(Degrees_To_Radians(degrees));
}

// Function to calculate cosine of an angle in degrees
double Cos_Deg(double degrees) {
    return cos(Degrees_To_Radians(degrees));
}
