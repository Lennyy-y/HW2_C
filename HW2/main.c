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
//    freeAirportArr(apm.allAirports, apm.airportCount);

    Airline *al = malloc(sizeof(Airline));
//    printAirline(al);
    initAirline(al);
    printf("%d\n", al->planeCount);
    printAirline(al);
//    if(al->allPlanes)
//        freePlaneArr(&al->allPlanes, al->planeCount);
    free(al);
}
