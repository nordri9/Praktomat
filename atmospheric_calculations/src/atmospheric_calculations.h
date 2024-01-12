#ifndef atmospheric_calculations_H
#define atmospheric_calculations_H

int atmospheric_calculations();
double calculations(char latitude, char longitude, char temperature,
                    int pressure);

double T(int temperature);
unsigned int p(unsigned int pressure_hpa);
int location_hight(char latitude, char longitude);
double stagnation_temperature(char latitude, char longitude,
                              int temperature_celsius);
double stagnation_pressure(unsigned int pressure_hpa, char latitude,
                           char longitude, int temperature_celsius);
double actual_density(unsigned int pressure_hpa, char latitude, char longitude,
                      int temperature_celsius);
double density_altitude(unsigned int pressure_hpa, char latitude,
                        char longitude, int temperature_celsius);
int atmospheric_calculations();
#endif
