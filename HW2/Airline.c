#include "Airline.h"
#include <stdio.h>
#include "generalStrings.h"

int addFlight(Airline* arl, Flight* fl)
{
    if (!isValidPlane(&(fl->plane)) || !strlen(fl->arrivalCode) || !strlen(fl->departureCode) || !isValidDate(&(fl->flightDate)))
        return 0;
    arl->allFlights[arl->flightCount++] = fl;
    return 1;
}
void addPlane(Airline* arl, Plane* pl)
{
    arl->allPlanes[arl->flightCount++] = *pl;
}
void doPrintFlightsWithPlaneType(Airline* arl, planeType planeT)
{
    for (int i = 0 ; i < arl->flightCount ; i++)
    {
        if (isPlaneTypeInFlight(arl->allFlights[i], planeT))
            printFlight(arl->allFlights[i]);
    }
}
#define MAX_AIRLINE_FLIGHTS 2
int initAirline(Airline* pAl)
{
    printf("Enter airline name:\n");
    myGets(pAl->airlineName, MAX_STR_LEN);
    pAl->flightCount = 0;
    if(!initFlightArr(pAl->allFlights, MAX_AIRLINE_FLIGHTS))
        return 0;
    pAl->flightCount = (int)(sizeof(*(pAl->allFlights)));
    printf("Enter plane amount\n");
    scanf("%d", &(pAl->planeCount));
    initPlaneArr(pAl->allPlanes, pAl->planeCount);
    return 1;


}
void printAirline(const Airline* pAl)
{
    if(pAl->flightCount != 0) {
        printf("Airline name %s has %d planes and %d flights.\n", pAl->airlineName, pAl->planeCount, pAl->flightCount);
        printf("Planes:\n");
        printPlaneArr(pAl->allPlanes, pAl->planeCount);
        printf("\nFlights:\n");
        printFlightArr((const Flight **) pAl->allFlights, pAl->flightCount);
    }
    else
        printf("Airline has no name or flights.\n");
}

