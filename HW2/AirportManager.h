#pragma once
#include "Airport.h"
#include <stdlib.h>
typedef struct
{
    int airportCount;
    Airport** allAirports;
}AirportManager;


int addAirport(AirportManager* arr);
Airport* findAirportByCode(AirportManager* arr, const char* IATA);
void initAirportManager(AirportManager* pApm);
void printAirportManager(const AirportManager* pApm);
