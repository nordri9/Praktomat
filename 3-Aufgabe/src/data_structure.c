#include "data_structures.h"
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

void printCoordinate(Coordinate *c)
{
  printf("Coordinate: %lf° %lf' %lf\"\n", c->degree, c->minute, c->second);
}

void printAirport(Airport *aport)
{
  printf("Airport ICAO: %s\n", aport->icao);
  printf("Airport IATA: %s\n", aport->iata);
  printf("Latitude: ");
  printCoordinate(&aport->latitude);
  printf("Longitude: ");
  printCoordinate(&aport->longitude);
  printf("Height AMSL: %f\n", aport->heightAMSL);
}

void printTime(Time *t)
{
  printf("Time: %02u:%02u\n", t->hour, t->minute);
}

void printFlightPath(FlightPath *fp)
{
  printf("Flight Path Name: %s\n", fp->flightPathName);
  printf("Departure Airport:\n");
  printAirport(fp->pDepartureAirport);
  printf("Arrival Airport:\n");
  printAirport(fp->pArrivalAirport);
  printf("Departure Time: ");
  printTime(&fp->departure);
  printf("Arrival Time: ");
  printTime(&fp->arrival);
}

void printAirplane(Airplane *aplane)
{
  printf("Airplane Name: %s\n", aplane->airplaneName);
  printf("Air Vehicle Registration: %s\n", aplane->airVehicleRegestriation);
  for (unsigned int i = 0; i < aplane->cntFlightPath; i++)
  {
    printf("Flight Path %u:\n", i + 1);
    printFlightPath(&aplane->pFlightPath[i]);
  }
}

void printAirline(Airline *al)
{
  printf("Airline Name: %s\n", al->airlineName);
  for (unsigned int i = 0; i < al->cntAirplane; i++)
  {
    printf("Airplane %u:\n", i + 1);
    printAirplane(&al->pAirplane[i]);
  }
}

void Generate_Time_Table(FMS *pFMS)
{
  
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");
  for (unsigned int i = 0; i < pFMS->cntAirline; i++)
  {
    printf("Airline %u:\n", i + 1);
    printAirline(&pFMS->pAirline[i]);
  }
}

/*
// Definition of the data function
int datatest()
{
  Coordinate test_c;
  initCoordinate(&test_c, 40.0, 20.0, 30.0);
  printCoordinate(&test_c);

  Airport test_a;
  initAirport(&test_a, "ABCD", "ABC", 33.9425, 118.4081, 0.0, -118.4081, 0.0, 0.0, 125.0);
  printAirport(&test_a);
  return 0;
}
*/