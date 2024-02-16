#include <stdio.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Airline.h"
#include "Functions.h"
#include "Date.h"
#include "generalStrings.h"

int main() {
//    AirportManager apm = {0};
//    printAirportManager(&apm);
//    initAirportManager(&apm);
//    printAirportManager(&apm);
//    freeAirportArr(apm.allAirportPointers, apm.airportCount);

    Airline al = {0};
    printAirline(&al);
    initAirline(&al);
    printAirline(&al);
    freePlaneArr(al.allPlanes, al.planeCount);
}
