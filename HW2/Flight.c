#include "Flight.h"
#include <stdio.h>
#include <stdlib.h>
#include "generalStrings.h"



int isFlightFromSourceAirport(Flight* fl, char* IATA)
{
    if (!strcmp(fl->departureCode, IATA))
        return 1;
    return 0;
}
int isFlightToDestAirport(Flight* fl, char* IATA)
{
    if (!strcmp(fl->arrivalCode, IATA))
        return 1;
    return 0;
}
int isPlaneTypeInFlight(Flight* fl, planeType plType)
{
    if (fl->plane.type == plType)
        return 1;
    return 0;
}
void initFlight(Flight* pFl)
{
    printf("Enter departure IATA:\n");
    myGets(pFl->departureCode, IATA_LEN + 1);
    printf("Enter arrival IATA:\n");
    myGets(pFl->arrivalCode, IATA_LEN + 1);
    initPlane(&(pFl->plane));
    initDate(&(pFl->flightDate));
}
int initFlightArr(Flight** flArr, int count)
{
    for (int i = 0 ; i < count; i++)
    {
        flArr[i] = malloc(sizeof(Flight*));
        if(!flArr[i])
            return 0;
        initFlight(flArr[i]);
    }
    return 1;
}
void freeFlightArr(Flight** flArr, int size)
{
    for(int i = 0 ; i < size; i++)
        free(flArr[i]);
}

void printFlight(const Flight* pFl)
{
    printf("Departing from %s\nArriving at %s\n", pFl->departureCode, pFl->arrivalCode);
    printPlane(&(pFl->plane));
    printDate(&(pFl->flightDate));
}

void printFlightArr(const Flight** flArr, int size)
{
    for (int i = 0 ; i < size ; i++)
        printFlight(flArr[i]);
}