#include "flight_distance.h"
#include <math.h>
#include <stdio.h>

#define r 6378.388 // Radius of the Earth in kilometers

// Function to convert degrees, minutes, and seconds to decimal degrees
double calculateDegree(int degrees, int minutes, int seconds) {
  return degrees + (minutes / 60.0) + (seconds / 3600.0);
}

// Function to calculate the sine of an angle in degrees
double sinDeg(double degrees) { return sin(degrees * M_PI / 180.0); }

// Function to calculate the cosine of an angle in degrees
double cosDeg(double degrees) { return cos(degrees * M_PI / 180.0); }

// Function to calculate the distance between two geographical points using
// Haversine formula
double DisCalc(double arrlat, double deplat, double arrlon, double deplon) {
  double distance =
      r * acos(sinDeg(arrlat) * sinDeg(deplat) +
               cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
  return distance;
}

// Main function to calculate and display flight distance
int flight_distance() {
  // Variables for storing degrees, minutes, and seconds for departure and
  // arrival
  char deplat_degree, deplat_minutes, deplat_seconds, deplon_degree,
      deplon_minutes, deplon_seconds;
  char arrlat_degree, arrlat_minutes, arrlat_seconds, arrlon_degree,
      arrlon_minutes, arrlon_seconds;

  // Prompt the user to enter latitude and longitude for departure and arrival
  printf("Please enter latitude in ° ’ ” and longitude in ° ’ ” for departure "
         "and arrival: ");
  // Read input in the specified format
  scanf("%hhd° %hhd' %hhd'' %hhd° %hhd' %hhd'' %hhd° %hhd' %hhd'' %hhd° %hhd' "
        "%hhd''",
        &deplat_degree, &deplat_minutes, &deplat_seconds, &deplon_degree,
        &deplon_minutes, &deplon_seconds, &arrlat_degree, &arrlat_minutes,
        &arrlat_seconds, &arrlon_degree, &arrlon_minutes, &arrlon_seconds);

  // Convert degrees, minutes, and seconds to decimal degrees
  double deplat =
      calculateDegree(deplat_degree, deplat_minutes, deplat_seconds);
  double deplon =
      calculateDegree(deplon_degree, deplon_minutes, deplon_seconds);
  double arrlat =
      calculateDegree(arrlat_degree, arrlat_minutes, arrlat_seconds);
  double arrlon =
      calculateDegree(arrlon_degree, arrlon_minutes, arrlon_seconds);

  // Calculate and display the flight distance in kilometers
  printf("Flight Distance in km is %.2f\n",
         DisCalc(arrlat, deplat, arrlon, deplon));
  return 0;
}
