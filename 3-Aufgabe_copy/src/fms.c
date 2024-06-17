#include "fms.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define r 6378.388

void printAirport(Airport *aport)
{
    printf(" %s|", aport->iata);
}

void printDepartureTime(Time *t)
{
    printf("    %02u:%02u|", t->hour, t->minute);
}

void printArrivalTime(Time *t)
{
    printf("   %02u:%02u|", t->hour, t->minute);
}

int calculate_duration_minutes(Time *departure, Time *arrival)
{
    int dep_minutes = departure->hour * 60 + departure->minute;
    int arr_minutes = arrival->hour * 60 + arrival->minute;

    if (arr_minutes < dep_minutes)
    {
        arr_minutes += 24 * 60;
    }

    return arr_minutes - dep_minutes;
}

void printDuration(Time *departure, Time *arrival)
{
    int duration_minutes = calculate_duration_minutes(departure, arrival);
    int hours = duration_minutes / 60;
    int minutes = duration_minutes % 60;

    printf("  %02d:%02d\n", hours, minutes);
}

double calculateDegree(double degrees, double minutes, double seconds)
{
    return degrees + (minutes / 60.0) + (seconds / 3600.0);
}

double sinDeg(double degrees)
{
    return sin(degrees * M_PI / 180.0);
}

double cosDeg(double degrees)
{
    return cos(degrees * M_PI / 180.0);
}

double calculate_distance(Airport *pDepatureAirport, Airport *ArrivalAirport)
{
    double deplat = calculateDegree(pDepatureAirport->latitude.degree, pDepatureAirport->latitude.minute, pDepatureAirport->latitude.second);
    double deplon = calculateDegree(pDepatureAirport->longitude.degree, pDepatureAirport->longitude.minute, pDepatureAirport->longitude.second);
    double arrlat = calculateDegree(ArrivalAirport->latitude.degree, ArrivalAirport->latitude.minute, ArrivalAirport->latitude.second);
    double arrlon = calculateDegree(ArrivalAirport->longitude.degree, ArrivalAirport->longitude.minute, ArrivalAirport->longitude.second);
    double distance = r * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
    return distance;
}

void printDistance(Airport *DepartureAirport, Airport *ArrivalAirport)
{
    printf(" %.2f\n", calculate_distance(DepartureAirport, ArrivalAirport));
}

void printFlightPath(FlightPath *fp, unsigned char table_type)
{
    switch (table_type)
    {
    case 0:
        printf("   %s|", fp->flightPathName);
        printAirport(fp->pDepartureAirport);
        printAirport(fp->pArrivalAirport);
        printDepartureTime(&fp->departure);
        printArrivalTime(&fp->arrival);
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