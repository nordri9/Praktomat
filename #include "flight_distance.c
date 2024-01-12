#include "flight_distance.h"
#include <math.h>
#include <stdio.h>

#define r 6378.388

float caculateDegree(char degrees, char minutes, char seconds) {

  float decimalDegrees = degrees + (minutes / 60.0) + (seconds / 3600.0);
  return decimalDegrees;
}

float sinDeg(float degrees) { return sin(degrees * M_PI / 180.0); }

float cosDeg(float degrees) { return cos(degrees * M_PI / 180.0); }

double DisCalc(double arrlat, double deplat, double arrlon, double deplon) {
  double distance =
      r * acos(sinDeg(arrlat) * sinDeg(deplat) +
               cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
  return distance;
}

int flight_distance() {

  typedef struct {
    char degrees;
    char minutes;
    char seconds;
  } Sexagesimal_coordinates;

  Sexagesimal_coordinates coordinates_sexagesimal[4];

  printf("Please enter latitude in ° ’ ” and longitude in ° ’ ” for departure "
         "and arrival: ");

  for (int i = 0; i < 4; ++i) {

    scanf("%hhd° %hhd’ %hhd”", &coordinates_sexagesimal[i].degrees,
          &coordinates_sexagesimal[i].minutes,
          &coordinates_sexagesimal[i].seconds);
  }

  float coordinates_decimal[4];

  for (int i = 0; i < 4; ++i) {

    coordinates_decimal[i] = caculateDegree(coordinates_sexagesimal[i].degrees,
                                            coordinates_sexagesimal[i].minutes,
                                            coordinates_sexagesimal[i].seconds);
  }

  float deplat = coordinates_decimal[0];
  float deplon = coordinates_decimal[1];
  float arrlat = coordinates_decimal[2];
  float arrlon = coordinates_decimal[3];

  printf("Flight Distance in km is %.2f\n",
         DisCalc(arrlat, deplat, arrlon, deplon));

  return 0; // Erfolgreich beendet
}