#include "AirportManager.h"
#include <stdlib.h>
#include <stdio.h>

int addAirport(AirportManager* apmP)
{
    Airport* ap = malloc(sizeof(Airport));

    for (int i = 0 ; i < apmP->airportCount ; i++)
    {
        if(isSameAirport(apmP->allAirports[i], ap))
            return 0;
    }
    initAirport(ap);
    apmP->allAirports[apmP->airportCount++] = ap;
    return 1;
}
Airport* findAirportByCode(AirportManager* arr, const char IATA[IATA_LEN + 1])
{
    Airport* ap;
    Airport ap_search = {"", "", *IATA};
    ap = bsearch(&ap_search, arr->allAirports, arr->airportCount, sizeof(Airport),
                 (int (*)(const void *, const void *)) isSameAirport);
    return ap;
}
void initAirportManager(AirportManager* pApm)
{
    pApm->airportCount = 0;
}
void printAirportManager(const AirportManager* pApm)
{
    if(pApm->airportCount != 0) {
        printf("There are %d airports:\n", pApm->airportCount);
        printAirportArr((const Airport **) pApm->allAirports, pApm->airportCount);
    }
    else
        printf("Airport Manager has 0 airports\n");
}