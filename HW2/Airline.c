#include "Airline.h"
#include <stdio.h>
#include <stdlib.h>
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
    arl->allPlanes[arl->planeCount++] = *pl;
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
    pAl->airlineName = malloc(MAX_STR_LEN);
    printf("Enter airline name:\n");
    myGets(pAl->airlineName, MAX_STR_LEN);
    pAl->flightCount = 0;
    pAl->planeCount = 0;
    printf("Enter flight amount\n");
    scanf("%d", &pAl->flightCount);
    pAl->allFlights = malloc(pAl->flightCount*sizeof(Flight*));
    initFlightArr(pAl->allFlights, pAl->flightCount);

    printf("Enter plane amount\n");
    scanf("%d", &pAl->planeCount);
    printf("%d\n", pAl->planeCount);
    pAl->allPlanes = malloc(pAl->planeCount*sizeof(Plane));
    initPlaneArr(&pAl->allPlanes, pAl->planeCount);
    return 1;


}
void printAirline(const Airline* pAl)
{
        printf("Airline name %s has %d planes and %d flights.\n", pAl->airlineName, pAl->planeCount, pAl->flightCount);
        printf("List of planes:\n");
        printPlaneArr((const Plane **) pAl->allPlanes, pAl->planeCount);
        printf("\nFlights:\n");
        printFlightArr((const Flight **) pAl->allFlights, pAl->flightCount);

}

