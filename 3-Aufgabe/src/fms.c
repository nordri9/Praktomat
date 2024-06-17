#include "fms.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define r 6378.388 // Radius of the Earth in kilometers



/**
 * Initializes a Coordinate struct with the given values.
 *
 * @param c A pointer to the Coordinate struct to be initialized.
 * @param degree The degree value of the coordinate.
 * @param minute The minute value of the coordinate.
 * @param second The second value of the coordinate.
 */
void initCoordinate(Coordinate *c, double degree, double minute, double second)
{
    c->degree = degree;
    c->minute = minute;
    c->second = second;
}


/**
 * Initializes an Airport struct with the given values.
 *
 * @param a A pointer to the Airport struct to be initialized.
 * @param icao A null-terminated string representing the ICAO code of the airport.
 * @param iata A null-terminated string representing the IATA code of the airport.
 * @param latDegree The degree value of the latitude.
 * @param latMinute The minute value of the latitude.
 * @param latSecond The second value of the latitude.
 * @param lonDegree The degree value of the longitude.
 * @param lonMinute The minute value of the longitude.
 * @param lonSecond The second value of the longitude.
 * @param heightAMSL The height above mean sea level in meters.
 */
void initAirport(Airport *a, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL)
{
    strncpy(a->icao, icao, sizeof(a->icao) - 1);
    a->icao[sizeof(a->icao) - 1] = '\0';

    strncpy(a->iata, iata, sizeof(a->iata) - 1);
    a->iata[sizeof(a->iata) - 1] = '\0';

    initCoordinate(&a->latitude, latDegree, latMinute, latSecond);
    initCoordinate(&a->longitude, lonDegree, lonMinute, lonSecond);
    a->heightAMSL = heightAMSL;
}



// Initializes a Time struct with the given hour and minute values.
// 
// Parameters:
// - t: A pointer to the Time struct to be initialized.
// - hour: An unsigned char representing the hour value.
// - minute: An unsigned char representing the minute value.
void initTime(Time *t, unsigned char hour, unsigned char minute)
{
    t->hour = hour;
    t->minute = minute;
}


/**
 * Initializes a FlightPath struct with the given flight path details.
 *
 * @param fp A pointer to the FlightPath struct to be initialized.
 * @param flightPathName The name of the flight path.
 * @param pDepartureAirport A pointer to the departure airport.
 * @param pArrivalAirport A pointer to the arrival airport.
 * @param depHour The hour of departure.
 * @param depMinute The minute of departure.
 * @param arrHour The hour of arrival.
 * @param arrMinute The minute of arrival.
 */
void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *ppArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute)
{
    strncpy(fp->flightPathName, flightPathName, sizeof(fp->flightPathName) - 1);
    fp->flightPathName[sizeof(fp->flightPathName) - 1] = '\0'; // Ensure null termination

    fp->pDepartureAirport = pDepartureAirport;
    fp->pArrivalAirport = ppArrivalAirport;

    initTime(&fp->departure, depHour, depMinute);
    initTime(&fp->arrival, arrHour, arrMinute);
}


/**
 * Initializes an Airplane struct with the given airplane details.
 *
 * @param aplane A pointer to the Airplane struct to be initialized.
 * @param airplaneName The name of the airplane.
 * @param airVehicleRegestriation The registration number of the airplane.
 * @param pFlightPath A pointer to the FlightPath struct representing the airplane's flight path.
 * @param cntFlightPath The number of flight paths associated with the airplane.
 */
void initAirplane(Airplane *aplane, const char *airplaneName, const char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath)
{
    strncpy(aplane->airplaneName, airplaneName, sizeof(aplane->airplaneName) - 1);
    aplane->airplaneName[sizeof(aplane->airplaneName) - 1] = '\0'; // Ensure null termination

    strncpy(aplane->airVehicleRegestriation, airVehicleRegestriation, sizeof(aplane->airVehicleRegestriation) - 1);
    aplane->airVehicleRegestriation[sizeof(aplane->airVehicleRegestriation) - 1] = '\0'; // Ensure null termination

    aplane->pFlightPath = pFlightPath;
    aplane->cntFlightPath = cntFlightPath;
}

/**
 * Initializes an Airline struct with the given airline details.
 *
 * @param al A pointer to the Airline struct to be initialized.
 * @param airlineName The name of the airline.
 * @param pAirplane A pointer to the Airplane struct representing the airline's airplanes.
 * @param cntAirplane The number of airplanes associated with the airline.
 */
void initAirline(Airline *al, const char *airlineName, Airplane *pAirplane, unsigned int cntAirplane)
{
    strncpy(al->airlineName, airlineName, sizeof(al->airlineName) - 1);
    al->airlineName[sizeof(al->airlineName) - 1] = '\0'; // Ensure null termination

    al->pAirplane = pAirplane;
    al->cntAirplane = cntAirplane;
}

/**
 * Initializes the FMS struct with the given airline details.
 *
 * @param fms A pointer to the FMS struct to be initialized.
 * @param pAirline A pointer to the Airline struct representing the airlines.
 * @param cntAirline The number of airlines associated with the FMS.
 */
void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline)
{
    fms->pAirline = pAirline;
    fms->cntAirline = cntAirline;
}


/**
 * Prints the details of an Airport struct.
 *
 * @param aport A pointer to the Airport struct to be printed.
 */
void printAirport(Airport *aport)
{
    printf(" %s|", aport->iata);
}

/**
 * Prints the departure time in the format "hh:mm" for the given Time struct pointer.
 *
 * @param t A pointer to the Time struct containing the departure time.
 */
void printDepartureTime(Time *t)
{
    printf("    %02u:%02u|", t->hour, t->minute);
}

/**
 * Prints the arrival time in the format "hh:mm" for the given Time struct pointer.
 *
 * @param t A pointer to the Time struct containing the arrival time.
 */
void printpArrivalTime(Time *t)
{
    printf("   %02u:%02u|", t->hour, t->minute);
}


/**
 * Calculates the duration in minutes between the departure time and the arrival time.
 *
 * @param departure A pointer to the Time struct containing the departure time.
 * @param pArrival A pointer to the Time struct containing the arrival time.
 *
 * @return The duration in minutes between the departure and arrival times.
 *
 * @throws None
 */
int calculate_duration_minutes(Time *departure, Time *pArrival)
{
    int dep_minutes = departure->hour * 60 + departure->minute;
    int arr_minutes = pArrival->hour * 60 + pArrival->minute;

    if (arr_minutes < dep_minutes)
    {
        arr_minutes += 24 * 60;
    }

    return arr_minutes - dep_minutes;
}

/**
 * Prints the duration between two given times in the format HH:MM.
 *
 * @param departure A pointer to the Time struct representing the departure time.
 * @param pArrival A pointer to the Time struct representing the arrival time.
 *
 * @return None.
 *
 * @throws None.
 */
void printDuration(Time *departure, Time *pArrival)
{
    int duration_minutes = calculate_duration_minutes(departure, pArrival);
    int hours = duration_minutes / 60;
    int minutes = duration_minutes % 60;

    printf("  %02d:%02d\n", hours, minutes);
}

/**
 * Calculates the degree value by adding the degrees, minutes, and seconds.
 *
 * @param degrees The number of degrees.
 * @param minutes The number of minutes.
 * @param seconds The number of seconds.
 *
 * @return The calculated degree value.
 *
 * @throws None.
 */
double calculateDegree(double degrees, double minutes, double seconds)
{
    return degrees + (minutes / 60.0) + (seconds / 3600.0);
}

/**
 * Calculates the sine of a given angle in degrees.
 *
 * @param degrees The angle in degrees.
 * @return The sine of the given angle.
 */
double sinDeg(double degrees)
{
    return sin(degrees * M_PI / 180.0);
}

/**
 * Calculates the cosine of a given angle in degrees.
 *
 * @param degrees The angle in degrees.
 * @return The cosine of the given angle.
 */
double cosDeg(double degrees)
{
    return cos(degrees * M_PI / 180.0);
}

/**
 * Calculates the distance between two airports using the Haversine formula.
 *
 * @param DepartureAirport Pointer to the departure airport.
 * @param pArrivalAirport Pointer to the arrival airport.
 *
 * @return The distance between the two airports in kilometers.
 *
 * @throws None.
 */
double calculate_distance(Airport *DepartureAirport, Airport *pArrivalAirport)
{
    double deplat = calculateDegree(DepartureAirport->latitude.degree, DepartureAirport->latitude.minute, DepartureAirport->latitude.second);
    double deplon = calculateDegree(DepartureAirport->longitude.degree, DepartureAirport->longitude.minute, DepartureAirport->longitude.second);
    double arrlat = calculateDegree(pArrivalAirport->latitude.degree, pArrivalAirport->latitude.minute, pArrivalAirport->latitude.second);
    double arrlon = calculateDegree(pArrivalAirport->longitude.degree, pArrivalAirport->longitude.minute, pArrivalAirport->longitude.second);
    double distance = r * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
    return distance;
}

/**
 * Prints the distance between two airports.
 *
 * @param DepartureAirport Pointer to the departure airport.
 * @param pArrivalAirport Pointer to the arrival airport.
 *
 * @return None.
 *
 * @throws None.
 */
void printDistance(Airport *DepartureAirport, Airport *pArrivalAirport)
{
    printf(" %.2f\n", calculate_distance(DepartureAirport, pArrivalAirport));
}

/**
 * Prints the details of a flight path based on the specified table type.
 *
 * @param fp Pointer to the FlightPath struct representing the flight path.
 * @param table_type An unsigned char indicating the type of table to print.
 *                   0: Print flight path name, departure and arrival airports, departure and arrival times.
 *                   1: Print flight path name, departure and arrival airports, and distance between the airports.
 *                   2: Print flight path name, departure and arrival airports, and duration of the flight.
 *
 * @return None.
 *
 * @throws None.
 */
void printFlightPath(FlightPath *fp, unsigned char table_type)
{
    switch (table_type)
    {
    case 0:
        printf("   %s|", fp->flightPathName);
        printAirport(fp->pDepartureAirport);
        printAirport(fp->pArrivalAirport);
        printDepartureTime(&fp->departure);
        printpArrivalTime(&fp->arrival);
        break;
    case 1:
        printf("   %s|", fp->flightPathName);
        printAirport(fp->pDepartureAirport);
        printAirport(fp->pArrivalAirport);
        printDistance(fp->pDepartureAirport, fp->pArrivalAirport);
        break;
    case 2:
        printf("   %s|", fp->flightPathName);
        printAirport(fp->pDepartureAirport);
        printAirport(fp->pArrivalAirport);
        printDuration(&fp->departure, &fp->arrival);
        break;
    default:
        break;
    }
}

/**
 * Prints information about an airplane, including its airline name, flight paths,
 * and registration number, based on the specified table type.
 *
 * @param aplane Pointer to an Airplane struct containing flight path information.
 * @param airlineName Array of characters representing the airline name.
 * @param table_type Unsigned char representing the type of table to print.
 * @param cntAirline Unsigned int representing the number of airlines.
 */
void printAirplane(Airplane *aplane, char airlineName[32], unsigned char table_type, unsigned int cntAirline)
{
    for (unsigned int i = 0; i < aplane->cntFlightPath; i++)
    {
        switch (cntAirline)
        {
        case 2:
            printf("    %s|", airlineName);
            break;
        default:
            printf(" %s|", airlineName);
            break;
        }

        printFlightPath(&aplane->pFlightPath[i], table_type);
        if (table_type == 0)
        {
            printf("  %s\n", aplane->airVehicleRegestriation);
        }
    }
}

/**
 * Prints information about an airline, including the total flight distance or
 * total flight time, based on the specified table type.
 *
 * @param al Pointer to an Airline struct containing airplane information.
 * @param table_type Unsigned char representing the type of table to print.
 * @param cntAirline Unsigned int representing the number of airlines.
 *
 * @return None.
 *
 * @note This function iterates through each airplane in the airline and
 * calculates the total flight distance or total flight time based on the
 * specified table type. It then prints the result.
 */
void printAirline(Airline *al, unsigned char table_type, unsigned int cntAirline)
{
    double totalDistance = 0.0;
    int totalDurationMinutes = 0;

    for (unsigned int i = 0; i < al->cntAirplane; i++)
    {
        Airplane *aplane = &al->pAirplane[i];

        switch (table_type)
        {
        case 1:
            for (unsigned int j = 0; j < aplane->cntFlightPath; j++)
            {
                FlightPath *fp = &aplane->pFlightPath[j];
                totalDistance += calculate_distance(fp->pDepartureAirport, fp->pArrivalAirport);
            }
            break;
        case 2:
            for (unsigned int j = 0; j < aplane->cntFlightPath; j++)
            {
                FlightPath *fp = &aplane->pFlightPath[j];
                totalDurationMinutes += calculate_duration_minutes(&fp->departure, &fp->arrival);
            }
            break;
        default:
            break;
        }

        printAirplane(aplane, al->airlineName, table_type, cntAirline);
    }

    if (table_type == 1)
    {
        printf("\nTotal flight distance for %s %s is %.2f\n", al->airlineName, al->pAirplane->airplaneName, totalDistance);
    }

    if (table_type == 2)
    {
        int hours = totalDurationMinutes / 60;
        int minutes = totalDurationMinutes % 60;
        printf("\nTotal flight Time for %s %s is %02d:%02d\n", al->airlineName, al->pAirplane->airplaneName, hours, minutes);
    }
}

/**
 * Generates a time table for the given FMS (Flight Management System) structure.
 *
 * @param pFMS Pointer to the FMS structure.
 *
 * @return None.
 *
 * @throws None.
 */
void Generate_Time_Table(FMS *pFMS)
{
    unsigned char table_type = 0;
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");
    for (unsigned int i = 0; i < pFMS->cntAirline; i++)
    {
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}

/**
 * Generates a distance table for the given FMS (Flight Management System) structure.
 *
 * @param pFMS Pointer to the FMS structure.
 *
 * @return None.
 *
 * @throws None.
 */
void Generate_Distance_Table(FMS *pFMS)
{
    unsigned char table_type = 1;

    for (unsigned int i = 0; i < pFMS->cntAirline; i++)
    {
        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}

// Generates a duration table for the given FMS (Flight Management System) structure.
// 
// @param pFMS Pointer to the FMS structure.
// 
// @return None.
// 
// @throws None.
void Generate_Duration_Table(FMS *pFMS)
{
    unsigned char table_type = 2;

    for (unsigned int i = 0; i < pFMS->cntAirline; i++)
    {
        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}