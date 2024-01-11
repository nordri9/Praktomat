#include "flight_distance.h"
#include <math.h>
#include <stdio.h>

#define RADIUS_EARTH 6378.388 // Earth radius in kilometers

float calculateDegree(char degrees, char minutes, char seconds);
float sinDeg(float degrees);
float cosDeg(float degrees);

float calculateDegree(char degrees, char minutes, char seconds) {
  // Convert degrees, minutes, and seconds to decimal degrees
  float decimalDegrees = degrees + (minutes / 60.0) + (seconds / 3600.0);

  return decimalDegrees;
}

float sinDeg(float degrees) {
  // Convert degrees to radians
  float radians = degrees * (M_PI / 180.0);

  // Calculate sine value
  float sine_value = sin(radians);

  return sine_value;
}

float cosDeg(float degrees) {
  // Convert degrees to radians
  float radians = degrees * (M_PI / 180.0);

  // Calculate cosine value
  float cosine_value = cos(radians);

  return cosine_value;
}

int flight_distance() {
  typedef struct {
    char degrees;
    char minutes;
    char seconds;
  } Sexagesimal_coordinates;

  Sexagesimal_coordinates coordinates_sexagesimal[4];

  printf("Please enter latitude in ° ’ ” and longitude in ° ’ ” for departure "
         "and arrival:");

  for (int i = 0; i < 4; ++i) {
    scanf("%hhd° %hhd’ %hhd”", &coordinates_sexagesimal[i].degrees,
          &coordinates_sexagesimal[i].minutes,
          &coordinates_sexagesimal[i].seconds);
  }

  float coordinates_decimal[4];

  for (int i = 0; i < 4; ++i) {
    coordinates_decimal[i] = calculateDegree(
        coordinates_sexagesimal[i].degrees, coordinates_sexagesimal[i].minutes,
        coordinates_sexagesimal[i].seconds);
  }

  float deplat = coordinates_decimal[0];
  float deplon = coordinates_decimal[1];
  float arrlat = coordinates_decimal[2];
  float arrlon = coordinates_decimal[3];

  // Haversine formula
  double deltaLat = sinDeg((arrlat - deplat) / 2);
  double deltaLon = sinDeg((arrlon - deplon) / 2);

  double a = deltaLat * deltaLat +
             cosDeg(deplat) * cosDeg(arrlat) * deltaLon * deltaLon;

  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  double distance = RADIUS_EARTH * c;

  printf("\nFlight Distance in km is %lf\n", distance);
  return 0;
}
