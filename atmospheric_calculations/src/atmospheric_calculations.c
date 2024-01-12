#include "atmospheric_calculations.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Constants for gravitational acceleration, specific gas constant, gamma, and standard temperature and pressure
#define g 9.81
#define R 287
#define n 1.235
#define T0_constant 288.15
#define roh0_constant 1.225

// Function to convert temperature from Celsius to Kelvin
double T(int temperature) {
  double temperature_kelvin;
  return temperature_kelvin = temperature + 273.15;
}

// Function to convert pressure from hectopascal to pascal
unsigned int p(unsigned int pressure_hpa) {
  unsigned int pressure_pa;
  return pressure_pa = pressure_hpa * 1e2;
}

// Function to get the height of a location based on latitude and longitude
int location_height(char latitude, char longitude) {

  // Structure to represent location with latitude, longitude, and height
  typedef struct {
    char latitude;
    char longitude;
    int height;
  } Location;

  // Array of predefined locations with their latitude, longitude, and height
  Location locations[] = {
      {48, 9, 388}, {52, 13, 37}, {48, 11, 453}, {50, 8, 110}};

  // Iterate through the locations and return the height if coordinates match
  for (int i = 0; i < 4; ++i) {
    if (latitude == locations[i].latitude &&
        longitude == locations[i].longitude) {
      return locations[i].height;
    }
  }

  // Display an error message and exit the program if coordinates are incorrect
  printf("Wrong coordinates entered!\n");
  exit(0);
}

// Function to calculate stagnation temperature based on location and initial temperature
double stagnation_temperature(char latitude, char longitude,
                              int temperature_celsius) {

  // Stagnation temperature calculation using the provided formula
  double T0 = T(temperature_celsius) +
              ((n - 1) / n) * (g / R) * (location_height(latitude, longitude));

  return T0;
}

// Function to calculate stagnation pressure based on location, pressure, and
// initial temperature
double stagnation_pressure(unsigned int pressure_hpa, char latitude,
                           char longitude, int temperature_celsius) {
  // Stagnation pressure calculation using the provided formula
  double roh0 =
      p(pressure_hpa) /
      (R * stagnation_temperature(latitude, longitude, temperature_celsius));

  return roh0;
}

// Function to calculate actual air density based on location, pressure, and initial temperature
double actual_density(unsigned int pressure_hpa, char latitude, char longitude,
                      int temperature_celsius) {
  // Actual air density calculation using the provided formula
  double roh =
      stagnation_pressure(pressure_hpa, latitude, longitude,
                          temperature_celsius) *
      pow((1 - (n - 1) / n *
                   (g / (R * stagnation_temperature(latitude, longitude,
                                                    temperature_celsius))) *
                   location_height(latitude, longitude)),
          (1 / (n - 1)));
  return roh;
}

// Function to calculate density altitude based on location, pressure, and initial temperature
double density_altitude(unsigned int pressure_hpa, char latitude,
                        char longitude, int temperature_celsius) {
  // Density altitude calculation using the provided formula
  double H_of_roh = (pow((actual_density(pressure_hpa, latitude, longitude,
                                         temperature_celsius) /
                          roh0_constant),
                         (n - 1)) -
                     1) *
                    ((-1 * n) / (n - 1)) * ((R * T0_constant) / g);

  return H_of_roh;
}

// Function to perform atmospheric calculations
int atmospheric_calculations() {

  char latitude, longitude;
  int temperature_celsius;
  unsigned int pressure_hpa;

  // User input for latitude, longitude, temperature, and pressure
  printf("Please enter latitude, longitude, temperature and pressure for the "
         "airport: \n");

  scanf("%hhd %hhd %d %d", &latitude, &longitude, &temperature_celsius,
        &pressure_hpa);

  // Output the results of atmospheric calculations
  printf(
      "\nT_0 = %.3fK, rho_0 = %.3fkg/m³, rho = %.3fkg/m³, H = %.3fm\n",
      stagnation_temperature(latitude, longitude, temperature_celsius),
      stagnation_pressure(pressure_hpa, latitude, longitude,
                          temperature_celsius),
      actual_density(pressure_hpa, latitude, longitude, temperature_celsius),
      density_altitude(pressure_hpa, latitude, longitude, temperature_celsius));

  return 0;
}
