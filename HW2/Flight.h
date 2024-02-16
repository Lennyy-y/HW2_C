#pragma once
#include "Airport.h"
#include "Plane.h"
#include "Date.h"
typedef struct
{
    char departureCode[IATA_LEN + 1];
    char arrivalCode[IATA_LEN + 1];
    Plane plane;
    Date flightDate;
}Flight;

int isFlightFromSourceAirport(Flight* fl, char* IATA);
int isFlightToDestAirport(Flight* fl, char* IATA);
int isPlaneTypeInFlight(Flight* fl, planeType plType);
void initFlight(Flight* pFl);
int initFlightArr(Flight** flArr, int count);
void freeFlightArr(Flight** flArr, int size);
void printFlight(const Flight* pFl);
void printFlightArr(const Flight** flArr, int size);
