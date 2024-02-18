#pragma once
#include "Flight.h"
#include "Plane.h"
typedef struct
{
    char* airlineName;
    int flightCount;
    Plane* allPlanes;
    int planeCount;
    Flight** allFlights;
}Airline;

int addFlight(Airline* arl, Flight* fl);
void addPlane(Airline* arl, Plane* pl);
void doPrintFlightsWithPlaneType(Airline* arl, planeType planeT);
int initAirline(Airline* pAl);
void printAirline(const Airline* pAl);