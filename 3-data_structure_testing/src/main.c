#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define r 6371 // Radius of Earth in kilometers

typedef struct {
    double degree;
    double minute;
    double second;
} Coordinate;

typedef struct {
    char icao[5]; // 4 characters + null terminator
    char iata[4]; // 3 characters + null terminator
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
} Airport;

typedef struct {
    unsigned char hour;
    unsigned char minute;
} Time;

typedef struct {
    char flightPathName[32];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
} FlightPath;

typedef struct {
    char airplaneName[32];
    char airVehicleRegestriation[32];
    FlightPath *pFlightPath;
    unsigned int cntFlightPath;
} Airplane;

typedef struct {
    char airlineName[32];
    Airplane *pAirplane;
    unsigned int cntAirplane;
} Airline;

typedef struct {
    Airline *pAirline;
    unsigned int cntAirline;
} FMS;

// Function prototypes
void initCoordinate(Coordinate *c, double degree, double minute, double second);
void initAirport(Airport *a, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL);
void initTime(Time *t, unsigned char hour, unsigned char minute);
void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *pArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute);
void initAirplane(Airplane *aplane, const char *airplaneName, const char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath);
void initAirline(Airline *al, const char *airlineName, Airplane *pAirplane, unsigned int cntAirplane);
void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline);
void fms_data_input(FMS *pFMS);
void Generate_Time_Table(FMS *pFMS);
void Generate_Distance_Table(FMS *pFMS);
void Generate_Duration_Table(FMS *pFMS);
void printAirport(Airport *aport);
void printDepartureTime(Time *t);
void printArrivalTime(Time *t);
int calculate_duration_minutes(Time *departure, Time *arrival);
void printDuration(Time *departure, Time *arrival);
double calculateDegree(double degrees, double minutes, double seconds);
double sinDeg(double degrees);
double cosDeg(double degrees);
double calculate_distance(Airport *DepartureAirport, Airport *ArrivalAirport);
void printDistance(Airport *DepartureAirport, Airport *ArrivalAirport);
void printFlightPath(FlightPath *fp, unsigned char table_type);
void printAirplane(Airplane *aplane, char airlineName[32], unsigned char table_type, unsigned int cntAirline);
void printAirline(Airline *al, unsigned char table_type, unsigned int cntAirline);


void initCoordinate(Coordinate *c, double degree, double minute, double second) {
    c->degree = degree;
    c->minute = minute;
    c->second = second;
}

void initAirport(Airport *a, const char *icao, const char *iata, double latDegree, double latMinute, double latSecond, double lonDegree, double lonMinute, double lonSecond, float heightAMSL) {
    strncpy(a->icao, icao, sizeof(a->icao) - 1);
    a->icao[sizeof(a->icao) - 1] = '\0'; // Ensure null termination

    strncpy(a->iata, iata, sizeof(a->iata) - 1);
    a->iata[sizeof(a->iata) - 1] = '\0'; // Ensure null termination

    initCoordinate(&a->latitude, latDegree, latMinute, latSecond);
    initCoordinate(&a->longitude, lonDegree, lonMinute, lonSecond);
    a->heightAMSL = heightAMSL;
}

void initTime(Time *t, unsigned char hour, unsigned char minute) {
    t->hour = hour;
    t->minute = minute;
}

void initFlightPath(FlightPath *fp, const char *flightPathName, Airport *pDepartureAirport, Airport *pArrivalAirport, unsigned char depHour, unsigned char depMinute, unsigned char arrHour, unsigned char arrMinute) {
    strncpy(fp->flightPathName, flightPathName, sizeof(fp->flightPathName) - 1);
    fp->flightPathName[sizeof(fp->flightPathName) - 1] = '\0'; // Ensure null termination

    fp->pDepartureAirport = pDepartureAirport;
    fp->pArrivalAirport = pArrivalAirport;

    initTime(&fp->departure, depHour, depMinute);
    initTime(&fp->arrival, arrHour, arrMinute);
}

void initAirplane(Airplane *aplane, const char *airplaneName, const char *airVehicleRegestriation, FlightPath *pFlightPath, unsigned int cntFlightPath) {
    strncpy(aplane->airplaneName, airplaneName, sizeof(aplane->airplaneName) - 1);
    aplane->airplaneName[sizeof(aplane->airplaneName) - 1] = '\0'; // Ensure null termination

    strncpy(aplane->airVehicleRegestriation, airVehicleRegestriation, sizeof(aplane->airVehicleRegestriation) - 1);
    aplane->airVehicleRegestriation[sizeof(aplane->airVehicleRegestriation) - 1] = '\0'; // Ensure null termination

    aplane->pFlightPath = pFlightPath;
    aplane->cntFlightPath = cntFlightPath;
}

void initAirline(Airline *al, const char *airlineName, Airplane *pAirplane, unsigned int cntAirplane) {
    strncpy(al->airlineName, airlineName, sizeof(al->airlineName) - 1);
    al->airlineName[sizeof(al->airlineName) - 1] = '\0'; // Ensure null termination

    al->pAirplane = pAirplane;
    al->cntAirplane = cntAirplane;
}

void initFMS(FMS *fms, Airline *pAirline, unsigned int cntAirline) {
    fms->pAirline = pAirline;
    fms->cntAirline = cntAirline;
}

void fms_data_input(FMS *pFMS)
{

  static Airport hamburg, berlin, dusseldorf, cologne, frankfurt, stuttgart, munich;

  initAirport(&hamburg, "EDDH", "HAM", 53, 37, 49, 9, 59, 18, 16);
  initAirport(&berlin, "EDDB", "BER", 52, 21, 44, 13, 30, 2, 48);
  initAirport(&dusseldorf, "EDDL", "DUS", 51, 16, 51, 6, 45, 26, 45);
  initAirport(&cologne, "EDDK", "CGN", 50, 51, 57, 7, 8, 34, 92);
  initAirport(&frankfurt, "EDDF", "FRA", 50, 1, 59, 8, 34, 14, 111);
  initAirport(&stuttgart, "EDDS", "STR", 48, 41, 24, 9, 13, 19, 389);
  initAirport(&munich, "EDDM", "MUC", 48, 21, 14, 11, 47, 10, 453);

  static Time t0300, t0415, t0800, t1000, t1012, t1015, t1130, t1300, t1310, t1315, t1430, t1500, t1512, t1530, t1630, t1700, t1800, t1830, t2030, t2045, t2145, t2200, t2230, t2330, t2400;

  initTime(&t0300, 3, 0);
  initTime(&t0415, 4, 15);
  initTime(&t0800, 8, 0);
  initTime(&t1000, 10, 0);
  initTime(&t1012, 10, 12);
  initTime(&t1015, 10, 15);
  initTime(&t1130, 11, 30);
  initTime(&t1300, 13, 0);
  initTime(&t1310, 13, 10);
  initTime(&t1315, 13, 15);
  initTime(&t1430, 14, 30);
  initTime(&t1500, 15, 0);
  initTime(&t1512, 15, 12);
  initTime(&t1530, 15, 30);
  initTime(&t1630, 16, 30);
  initTime(&t1700, 17, 0);
  initTime(&t1800, 18, 0);
  initTime(&t1830, 18, 30);
  initTime(&t2030, 20, 30);
  initTime(&t2045, 20, 45);
  initTime(&t2145, 21, 45);
  initTime(&t2200, 22, 0);
  initTime(&t2230, 22, 30);
  initTime(&t2330, 23, 30);
  initTime(&t2400, 24, 0);

  static FlightPath MUC_HAM1, HAM_FRA1, FRA_HUC, MUC_HAM2, HAM_MUC, MUC_DUS1, DUS_BER, BER_CGN, CGN_MUC, MUC_DUS2, HAM_STR, STR_BER, BER_FRA, FRA_HAM, HAM_FRA2;

  initFlightPath(&MUC_HAM1, "LH 2147", &munich, &hamburg, t1130.hour, t1130.minute, t1430.hour, t1430.minute);
  initFlightPath(&HAM_FRA1, "LH 2147", &hamburg, &frankfurt, t1530.hour, t1530.minute, t1630.hour, t1630.minute);
  initFlightPath(&FRA_HUC, "LH 2147", &frankfurt, &munich, t1830.hour, t1830.minute, t2030.hour, t2030.minute);
  initFlightPath(&MUC_HAM2, "LH 2147", &munich, &hamburg, t2045.hour, t2045.minute, t2200.hour, t2200.minute);
  initFlightPath(&HAM_MUC, "LH 2147", &hamburg, &munich, t2230.hour, t2230.minute, t2330.hour, t2330.minute);
  initFlightPath(&MUC_DUS1, "EW 5953", &munich, &dusseldorf, t0300.hour, t0300.minute, t0415.hour, t0415.minute);
  initFlightPath(&DUS_BER, "EW 5953", &dusseldorf, &berlin, t0800.hour, t0800.minute, t1000.hour, t1000.minute);
  initFlightPath(&BER_CGN, "EW 5953", &berlin, &cologne, t1012.hour, t1012.minute, t1315.hour, t1315.minute);
  initFlightPath(&CGN_MUC, "EW 5953", &cologne, &munich, t1800.hour, t1800.minute, t2030.hour, t2030.minute);
  initFlightPath(&MUC_DUS2, "EW 5953", &munich, &dusseldorf, t2145.hour, t2145.minute, t2330.hour, t2330.minute);
  initFlightPath(&HAM_STR, "X3 2174", &hamburg, &stuttgart, t0800.hour, t0800.minute, t1000.hour, t1000.minute);
  initFlightPath(&STR_BER, "X3 2174", &stuttgart, &berlin, t1015.hour, t1015.minute, t1300.hour, t1300.minute);
  initFlightPath(&BER_FRA, "X3 2174", &berlin, &frankfurt, t1310.hour, t1310.minute, t1500.hour, t1500.minute);
  initFlightPath(&FRA_HAM, "X3 2174", &frankfurt, &hamburg, t1512.hour, t1512.minute, t1700.hour, t1700.minute);
  initFlightPath(&HAM_FRA2, "X3 2174", &hamburg, &frankfurt, t2200.hour, t2200.minute, t2400.hour, t2400.minute);

  static Airplane a380, a320, b747;

  FlightPath a380_flightpaths[] = {MUC_HAM1, HAM_FRA1, FRA_HUC, MUC_HAM2, HAM_MUC};
  FlightPath a320_flightpaths[] = {MUC_DUS1, DUS_BER, BER_CGN, CGN_MUC, MUC_DUS2};
  FlightPath b747_flightpaths[] = {HAM_STR, STR_BER, BER_FRA, FRA_HAM, HAM_FRA2};

  initAirplane(&a380, "A380", "D-AIMA", &a380_flightpaths[0], sizeof(a380_flightpaths) / sizeof(a380_flightpaths[0]));
  initAirplane(&a320, "A320", "D-AIAB", &a320_flightpaths[0], sizeof(a320_flightpaths) / sizeof(a320_flightpaths[0]));
  initAirplane(&b747, "B747", "D-ABCD", &b747_flightpaths[0], sizeof(b747_flightpaths) / sizeof(b747_flightpaths[0]));

  static Airline Lufthansa, EuroWings, TUIFly;

  initAirline(&Lufthansa, "Lufthansa", &a380, 1);
  initAirline(&EuroWings, "EuroWings", &a320, 1);
  initAirline(&TUIFly, "TUIFly", &b747, 1);

  Airline airlines[] = {Lufthansa, EuroWings, TUIFly};

  // FMS fms;

  initFMS(pFMS, airlines, sizeof(airlines) / sizeof(airlines[0]));
}

int main() {
    FMS fms;
    fms_data_input(&fms);

    printf("Airline Name: %s\n", fms.pAirline[0].airlineName);

    Generate_Time_Table(&fms);
    return 0;
}

void printAirport(Airport *aport) {
    printf(" %s|", aport->iata);
}

void printDepartureTime(Time *t) {
    printf("    %02u:%02u|", t->hour, t->minute);
}

void printArrivalTime(Time *t) {
    printf("   %02u:%02u|", t->hour, t->minute);
}

int calculate_duration_minutes(Time *departure, Time *arrival) {
    int dep_minutes = departure->hour * 60 + departure->minute;
    int arr_minutes = arrival->hour * 60 + arrival->minute;

    if (arr_minutes < dep_minutes) {
        arr_minutes += 24 * 60;
    }

    return arr_minutes - dep_minutes;
}

void printDuration(Time *departure, Time *arrival) {
    int duration_minutes = calculate_duration_minutes(departure, arrival);
    int hours = duration_minutes / 60;
    int minutes = duration_minutes % 60;

    printf("  %02d:%02d\n", hours, minutes);
}

double calculateDegree(double degrees, double minutes, double seconds) {
    return degrees + (minutes / 60.0) + (seconds / 3600.0);
}

double sinDeg(double degrees) {
    return sin(degrees * M_PI / 180.0);
}

double cosDeg(double degrees) {
    return cos(degrees * M_PI / 180.0);
}

double calculate_distance(Airport *DepartureAirport, Airport *ArrivalAirport) {
    double deplat = calculateDegree(DepartureAirport->latitude.degree, DepartureAirport->latitude.minute, DepartureAirport->latitude.second);
    double deplon = calculateDegree(DepartureAirport->longitude.degree, DepartureAirport->longitude.minute, DepartureAirport->longitude.second);
    double arrlat = calculateDegree(ArrivalAirport->latitude.degree, ArrivalAirport->latitude.minute, ArrivalAirport->latitude.second);
    double arrlon = calculateDegree(ArrivalAirport->longitude.degree, ArrivalAirport->longitude.minute, ArrivalAirport->longitude.second);
    double distance = r * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));
    return distance;
}

void printDistance(Airport *DepartureAirport, Airport *ArrivalAirport) {
    printf(" %.2f\n", calculate_distance(DepartureAirport, ArrivalAirport));
}

void printFlightPath(FlightPath *fp, unsigned char table_type) {
    switch (table_type) {
        case 0:
            printf("   %s|", fp->flightPathName);
            printAirport(fp->pDepartureAirport);
            printAirport(fp->pArrivalAirport);
            printDepartureTime(&fp->departure);
            printArrivalTime(&fp->arrival);
            break;
        case 1:
            printf("   %s|", fp->flightPathName);
            printAirport(fp->pDepartureAirport);
            printAirport(fp->pArrivalAirport);
            printDistance(fp->pDepartureAirport, fp->pArrivalAirport);
            break;
        case 2:
            printf("   %s|", fp->flightPathName);
            printAirport(fp->pDepartureAirport);
            printAirport(fp->pArrivalAirport);
            printDuration(&fp->departure, &fp->arrival);
            break;
        default:
            break;
    }
}

void printAirplane(Airplane *aplane, char airlineName[32], unsigned char table_type, unsigned int cntAirline) {
    for (unsigned int i = 0; i < aplane->cntFlightPath; i++) {
        switch (cntAirline) {
            case 2:
                printf("    %s|", airlineName);
                break;
            default:
                printf(" %s|", airlineName);
                break;
        }

        printFlightPath(&aplane->pFlightPath[i], table_type);
        if (table_type == 0) {
            printf("  %s\n", aplane->airVehicleRegestriation);
        }
    }
}

void printAirline(Airline *al, unsigned char table_type, unsigned int cntAirline) {
    double totalDistance = 0.0;
    int totalDurationMinutes = 0;

    for (unsigned int i = 0; i < al->cntAirplane; i++) {
        Airplane *aplane = &al->pAirplane[i];

        switch (table_type) {
            case 1:
                for (unsigned int j = 0; j < aplane->cntFlightPath; j++) {
                    FlightPath *fp = &aplane->pFlightPath[j];
                    totalDistance += calculate_distance(fp->pDepartureAirport, fp->pArrivalAirport);
                }
                break;
            case 2:
                for (unsigned int j = 0; j < aplane->cntFlightPath; j++) {
                    FlightPath *fp = &aplane->pFlightPath[j];
                    totalDurationMinutes += calculate_duration_minutes(&fp->departure, &fp->arrival);
                }
                break;
            default:
                break;
        }

        printAirplane(aplane, al->airlineName, table_type, cntAirline);
    }

    if (table_type == 1) {
        printf("\nTotal flight distance for %s %s is %.2f\n", al->airlineName, al->pAirplane->airplaneName, totalDistance);
    }

    if (table_type == 2) {
        int hours = totalDurationMinutes / 60;
        int minutes = totalDurationMinutes % 60;
        printf("\nTotal flight Time for %s %s is %02d:%02d\n", al->airlineName, al->pAirplane->airplaneName, hours, minutes);
    }
}

void Generate_Time_Table(FMS *pFMS) {
    unsigned char table_type = 0;
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");
    for (unsigned int i = 0; i < pFMS->cntAirline; i++) {
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}

void Generate_Distance_Table(FMS *pFMS) {
    unsigned char table_type = 1;

    for (unsigned int i = 0; i < pFMS->cntAirline; i++) {
        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}

void Generate_Duration_Table(FMS *pFMS) {
    unsigned char table_type = 2;

    for (unsigned int i = 0; i < pFMS->cntAirline; i++) {
        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");
        printAirline(&pFMS->pAirline[i], table_type, i);
    }
}