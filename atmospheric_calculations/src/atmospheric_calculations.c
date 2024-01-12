#include "atmospheric_calculations.h"
#include <math.h>
#include <stdio.h>

#define g 9.81
#define R 287
#define n 1.235
#define T0_constant 288.15
#define roh0_constant 1.225

float T(int temperature) {
  float temperature_kelvin;
  return temperature_kelvin = temperature + 273.15;
}

unsigned int p(unsigned int pressure_hpa) {
  unsigned int pressure_pa;
  return pressure_pa = pressure_hpa * 1e2;
}

int location_hight(char latitude, char longitude) {
  typedef struct {
    char latitude;
    char longitude;
    int height;
  } Location;

  Location locations[] = {
      {48, 9, 388}, {52, 13, 37}, {48, 11, 453}, {50, 8, 110}};

  for (int i = 0; i < 4; ++i) {
    if (latitude == locations[i].latitude ||
        longitude == locations[i].longitude) {
      return locations[i].height;
    }
  }

  printf("Wrong coordinates entered!");
  return 1;
}

float stagnation_temperature(char latitude, char longitude,
                             int temperature_celsius) {

  float T0 = T(temperature_celsius) +
             ((n - 1) / n) * (g / R) * (location_hight(latitude, longitude));

  return T0;
}

float stagnation_pressure(unsigned int pressure_hpa, char latitude,
                          char longitude, int temperature_celsius) {
  float roh0 =
      p(pressure_hpa) /
      (R * stagnation_temperature(latitude, longitude, temperature_celsius));

  return roh0;
}

float actual_density(unsigned int pressure_hpa, char latitude, char longitude,
                     int temperature_celsius) {
  float roh =
      stagnation_pressure(pressure_hpa, latitude, longitude,
                          temperature_celsius) *
      pow((1 - (n - 1) / n *
                   (g / (R * stagnation_temperature(latitude, longitude,
                                                    temperature_celsius))) *
                   location_hight(latitude, longitude)),
          (1 / (n - 1)));
  return roh;
}

float density_altitude(unsigned int pressure_hpa, char latitude, char longitude,
                       int temperature_celsius) {
  float H_of_roh =

      (pow((actual_density(pressure_hpa, latitude, longitude,
                           temperature_celsius) /
            roh0_constant),
           (n - 1)) -
       1)

      * ((-1 * n) / (n - 1)) * ((R * T0_constant) / g);

  return H_of_roh;
}

int atmospheric_calculations() {

  char latitude, longitude;
  int temperature_celsius;
  unsigned int pressure_hpa;

  printf("Please enter latitude, longitude, temperature and pressure for the "
         "airport: \n");

  scanf("%hhd %hhd %d %d", &latitude, &longitude, &temperature_celsius,
        &pressure_hpa);
  /*
    printf("hight: %d\n", location_hight(latitude, longitude));
    printf("Stagnation temperature: %f\n",
           stagnation_temperature(latitude, longitude, temperature_celsius));

    printf("Stagnation pressure: %f\n",
           stagnation_pressure(pressure_hpa, latitude, longitude,
                               temperature_celsius));

    printf(
        "Actual Density: %f\n",
        actual_density(pressure_hpa, latitude, longitude, temperature_celsius));

    printf(
        "Density altitude: %f\n",
        density_altitude(pressure_hpa, latitude, longitude,
    temperature_celsius));
  */

  printf(
      "\nT0 = %fK, rho0 = %fkg/m3, rho = %fkg/m3, H = "
      "%fm\n",
      stagnation_temperature(latitude, longitude, temperature_celsius),
      stagnation_pressure(pressure_hpa, latitude, longitude,
                          temperature_celsius),
      actual_density(pressure_hpa, latitude, longitude, temperature_celsius),
      density_altitude(pressure_hpa, latitude, longitude, temperature_celsius));
  return 0; // Erfolgreich beendet
}
