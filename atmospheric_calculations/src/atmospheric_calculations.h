#ifndef atmospheric_calculations_H
#define atmospheric_calculations_H

int atmospheric_calculations();
float calculations(char latitude, char longitude, char temperature,
                   int pressure);

float T(int temperature);
unsigned int p(unsigned int pressure_hpa);
int location_hight(char latitude, char longitude);
float stagnation_temperature(char latitude, char longitude,
                             int temperature_celsius);
float stagnation_pressure(unsigned int pressure_hpa, char latitude,
                          char longitude, int temperature_celsius);
float actual_density(unsigned int pressure_hpa, char latitude, char longitude,
                     int temperature_celsius);
float density_altitude(unsigned int pressure_hpa, char latitude, char longitude,
                       int temperature_celsius);
int atmospheric_calculations();
#endif
