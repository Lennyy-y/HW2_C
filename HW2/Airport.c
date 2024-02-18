
#include "Airport.h"
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "generalStrings.h"

int isSameAirport(void* ap1, void* ap2)
{
    Airport* airport1 = (Airport*) ap1;
    Airport* airport2 = (Airport*) ap2;
    if(!strcmp(airport1->code, airport2->code))
        return 1;
    return 0;
}
int isAirportCode(Airport* ap, char* IATA)
{
    if (!strcmp(ap->code, IATA))
        return 1;
    return 0;
}
char* getAirportName()
{
    char* apName = malloc(MAX_STR_LEN);
    printf("Enter airport name:\n");
    myGets(apName, MAX_STR_LEN);
    trimWhiteSpace(apName);
    numOfWords(apName);
    capitalizeFirstLetters(apName);
    return apName;
}

void initAirport(Airport* pAp)
{
    pAp->name = getAirportName();
    pAp->country = getStrExactLength("Enter airport country:");
    printf("Enter IATA (Max length %d)\n", IATA_LEN);
    myGets(pAp->code, IATA_LEN + 1);
}
int initAirportArr(Airport** apArr, int size)
{
    for (int i = 0 ; i < size; i++)
    {
        apArr[i] = malloc(sizeof(Airport));
        if(!apArr[i])
            return 0;
        initAirport(apArr[i]);
    }
    return 1;
}
void freeAirportArr(Airport** apArr, int size)
{
    for(int i = 0 ; i < size; i++) {
        free(apArr[i]->name);
        free(apArr[i]->country);
        free(apArr[i]->code);
        free(apArr[i]);
    }
}
void printAirport(const Airport* pAp)
{
    printf("Airport name: %s\nAirport country: %s\nIATA: %s\n", pAp->name, pAp->country, pAp->code);
}
void printAirportArr(const Airport** apArr, int size)
{
    for(int i = 0 ; i < size ; i++)
        printAirport(apArr[i]);
}
