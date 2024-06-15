#include "fms.h"
#include <stdio.h>
#include <string.h>

void initCoordinate(Coordinate *c, double degree, double minute, double second)
{
  c->degree = degree;
  c->minute = minute;
  c->second = second;
}

void initAirport(Airport *aport, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL)
{
  strncpy(aport->icao, icao, 5);
  aport->icao[4] = '\0';

  strncpy(aport->iata, iata, 4);
  aport->iata[3] = '\0';

  initCoordinate(&aport->latitude, latDegree, latMinute, latSecond);
  initCoordinate(&aport->longitude, lonDegree, lonMinute, lonSecond);

  aport->heightAMSL = heightAMSL;
}

void initTime(Time *t, unsigned char hour, unsigned char minute)
{
  t->hour = hour;
  t->minute = minute;
}

void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *pArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute)
{
  strncpy(fp->flightPathName, flightPathName, 32);
  fp->flightPathName[31] = '\0';

  fp->pDepartureAirport = pDepartureAirport;
  fp->pArrivalAirport = pArrivalAirport;

  initTime(&fp->departure, depHour, depMinute);
  initTime(&fp->arrival, arrHour, arrMinute);
}

void initAirplane(Airplane *aplane, char *airplaneName, char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath)
{
  strncpy(aplane->airplaneName, airplaneName, 32);
  aplane->airplaneName[31] = '\0';
  strncpy(aplane->airVehicleRegestriation, airVehicleRegestriation, 32);
  aplane->airVehicleRegestriation[31] = '\0';
  aplane->pFlightPath = pFlightPath;
  aplane->cntFlightPath = cntFlightPath;
}

void initAirline(Airline *al, char *airlineName, Airplane *pAirplane, unsigned int cntAirplane)
{
  strncpy(al->airlineName, airlineName, 32);
  al->airlineName[31] = '\0';
  al->pAirplane = pAirplane;
  al->cntAirplane = cntAirplane;
}

void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline)
{
  fms->pAirline = pAirline;
  fms->cntAirline = cntAirline;
}

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

void printFlightPath(FlightPath *fp)
{
  printf("   %s|", fp->flightPathName);

  printAirport(fp->pDepartureAirport);
  printAirport(fp->pArrivalAirport);
  printDepartureTime(&fp->departure);
  printArrivalTime(&fp->arrival);
}

void printAirplane(Airplane *aplane, int i, char airlineName[32])
{
  for (unsigned int i = 0; i < aplane->cntFlightPath; i++)
  {
    printf(" %s|", airlineName);
    printFlightPath(&aplane->pFlightPath[i]);
    printf("  %s\n", aplane->airVehicleRegestriation);
  }
}

void printAirline(Airline *al)
{
  for (unsigned int i = 0; i < al->cntAirplane; i++)
  {
    printAirplane(&al->pAirplane[i], i, al->airlineName);
  }
}

void Generate_Time_Table(FMS *pFMS)
{
  printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
  printf("----------|----------|----|----|---------|--------|--------\n");
  for (unsigned int i = 0; i < pFMS->cntAirline; i++)
  {
    printAirline(&pFMS->pAirline[i]);
  }
}

void Generate_Distance_Table(FMS *pFMS)
{
  for (unsigned int i = 0; i < pFMS->cntAirline; i++)
  {

    printf("   Airline|Flight No.|from|  to|Distance\n");
    printf("----------|----------|----|----|--------\n");
    printAirline(&pFMS->pAirline[i]);


  }
}
void Generate_Duration_Table(FMS *pFMS)
{
  printf("   Airline|Flight No.|from|  to|Duration\n");
  printf("----------|----------|----|----|--------\n");
}