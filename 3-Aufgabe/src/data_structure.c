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

void printAirport(const Airport *aport)
{
  printf("ICAO: %s\n", aport->icao);
  printf("IATA: %s\n", aport->iata);
  printf("Latitude: %.2f° %.2f' %.2f\"\n", aport->latitude.degree, aport->latitude.minute, aport->latitude.second);
  printf("Longitude: %.2f° %.2f' %.2f\"\n", aport->longitude.degree, aport->longitude.minute, aport->longitude.second);
  printf("Height AMSL: %.2f meters\n", aport->heightAMSL);
}

void printCoordinate(const Coordinate *c)
{
  printf("Degree: %.2f\n", c->degree);
  printf("Minute: %.2f\n", c->minute);
  printf("Second: %.2f\n", c->second);
}

void printTime(const Time *t)
{
  printf("Time: %02u:%02u\n", t->hour, t->minute);
}

void printFlightPath(const FlightPath *fp) {

    printf("Flight path name: %s\n", fp->flightPathName);
    

}

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