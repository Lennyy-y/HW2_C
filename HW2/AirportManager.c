#include "AirportManager.h"
#include <stdlib.h>
#include <stdio.h>

int addAirport(AirportManager* arr, Airport* ap)
{
    if (!strlen(ap->code)|| !ap->name || !ap->country)
        return 0;
    for (int i = 0 ; i < arr->airportCount ; i++)
    {
        if(isSameAirport(arr->allAirportPointers[i], ap))
            return 0;
    }
    arr->allAirportPointers[arr->airportCount++] = ap;
    return 1;
}
Airport* findAirportByCode(AirportManager* arr, const char* IATA)
{
    Airport* ap;
    Airport ap_search = {"", "", "IATA"};
    ap = bsearch(&ap_search, arr->allAirportPointers, arr->airportCount, sizeof(Airport),
                 (int (*)(const void *, const void *)) isSameAirport);
    return ap;
}
void initAirportManager(AirportManager* pApm)
{
    printf("Enter amount of airports\n");
    scanf("%d", &pApm->airportCount);
    initAirportArr(pApm->allAirportPointers, pApm->airportCount);
}
void printAirportManager(const AirportManager* pApm)
{
    if(pApm->airportCount != 0) {
        printf("There are %d airports:\n", pApm->airportCount);
        printAirportArr((const Airport **) pApm->allAirportPointers, pApm->airportCount);
    }
    else
        printf("Airport Manager has 0 airports\n");
}