#pragma once
#include "Airport.h"
#include <stdlib.h>
typedef struct
{
    int airportCount;
    Airport* allAirportPointers[];
}AirportManager;


int addAirport(AirportManager* arr, Airport* ap);
Airport* findAirportByCode(AirportManager* arr, const char* IATA);
void initAirportManager(AirportManager* pApm);
void printAirportManager(const AirportManager* pApm);
