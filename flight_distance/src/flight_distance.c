#include "flight_distance.h"

#include <math.h>
#include <stdio.h>

#define r 6378.388

float caculateDegree(char degrees, char minutes, char seconds) {
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

  // Calculate sine value
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

  /* const char *coordinates_sexagesimal_names[] = {
      "Departure Latitude", "Departure Longitude", "Arrival Latitude",
      "Arrival Longitude"};*/

  printf("Please enter latitude in ° ’ ” and longitude in ° ’ ” for departure and arrival: ");

  for (int i = 0; i < 4; ++i) {

    scanf("%hhd° %hhd’ %hhd”", &coordinates_sexagesimal[i].degrees,
          &coordinates_sexagesimal[i].minutes,
          &coordinates_sexagesimal[i].seconds);
  }
  /*
    // Print the values
    for (int i = 0; i < 4; ++i) {
      printf("\n%s: %hd° %hd’ %hd”", coordinates_sexagesimal_names[i],
             coordinates_sexagesimal[i].degrees,
             coordinates_sexagesimal[i].minutes,
             coordinates_sexagesimal[i].seconds);
    }
  */
  float coordinates_decimal[4];

  for (int i = 0; i < 4; ++i) {
    /* printf("\n%s: %lf", coordinates_sexagesimal_names[i],
            caculateDegree(coordinates_sexagesimal[i].degrees,
                           coordinates_sexagesimal[i].minutes,
                           coordinates_sexagesimal[i].seconds));*/

    coordinates_decimal[i] = caculateDegree(coordinates_sexagesimal[i].degrees,
                                            coordinates_sexagesimal[i].minutes,
                                            coordinates_sexagesimal[i].seconds);
  }

  float deplat = coordinates_decimal[0];
  float deplon = coordinates_decimal[1];
  float arrlat = coordinates_decimal[2];
  float arrlon = coordinates_decimal[3];
  float distance;
  printf("\nFlight Distance in km is %lf\n",
         distance = r * acos(sinDeg(arrlat) * sinDeg(deplat) +
                             cosDeg(arrlat) * cosDeg(deplat) *
                                 cosDeg(arrlon - deplon)));
  return 0; // Erfolgreich beendet
}
