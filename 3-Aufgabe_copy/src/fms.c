#include "fms.h"
#include <stdio.h>
#include <string.h>

void Generate_Time_Table(FMS *pFMS)
{
  if (pFMS == NULL || pFMS->cntAirline == 0)
  {
    printf("No data available.\n");
    return;
  }

  printf("   Airline|Flight No.| from|   to|Departure| Arrival|    Airplane\n");
  printf("----------|----------|-----|-----|---------|--------|-------------\n");

  for (unsigned int i = 0; i < pFMS->cntAirline; i++)
  {
    Airline *airline = &pFMS->pAirline[i];

    for (unsigned int j = 0; j < airline->cntAirplane; j++)
    {
      Airplane *airplane = &airline->pAirplane[j];

      for (unsigned int k = 0; k < airplane->cntFlightPath; k++)
      {
        FlightPath *flightPath = &airplane->pFlightPath[k];

        printf("%10s|%10s| %4s| %4s|  %02d:%02d  | %02d:%02d | %s\n",
               airline->airlineName,
               flightPath->flightPathName,
               flightPath->pDepartureAirport->iata,
               flightPath->pArrivalAirport->iata,
               flightPath->departure.hour,
               flightPath->departure.minute,
               flightPath->arrival.hour,
               flightPath->arrival.minute,
               airplane->airplaneName);
      }
    }
  }
}

/*
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
}*/