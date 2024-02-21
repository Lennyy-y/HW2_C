#include "Airport.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Functions.h"
#include "generalStrings.h"
#define MAX_STR_LEN 255

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
void  getAirportName(Airport* ap)
{
    char* apName = (char*) malloc(MAX_STR_LEN);
    printf("Enter airport name\n");
    myGets(apName, MAX_STR_LEN);
    trimWhiteSpace(apName);
    numOfWords(apName);
    capitalizeFirstLetters(apName);
    ap->name=apName;
}

void  getAirportCountry(Airport* pAp)
{

    printf("Enter airport country:\n");
    myGets(pAp->country, MAX_STR_LEN);

}

void getAirportCode(char* code)
{
    int wrong=1;
    char temp[MAX_STR_LEN];
    while(1)
    {
        memset(temp,0,MAX_STR_LEN);
        printf("Enter airport code  - %d UPPER CASE letters\n", IATA_LEN);
        myGets(temp,MAX_STR_LEN);
        if( strlen(temp) != IATA_LEN )
        {
            printf("code should be 3 letters\n");
            continue;
        }
        for ( int i = 0; i < 3; i++)
        {
            if( !isupper(temp[i]) )
            {
                printf("Need to be upper case letter\n");
                wrong=0;
                break;
            }
        }
        if( wrong == 0)
        {
            wrong=1;
            continue;
        }
           strcpy(code,temp);
        break;
    }
}
void initAirport(Airport* pAp)
{
    getAirportName(pAp);
    getAirportCountry(pAp);
    getAirportCode(pAp->code);

}

void initAirportNoCode(Airport* pAp) //only for the caseine
{

    getAirportName(pAp);
     getAirportCountry(pAp);

}

int initAirportArr(Airport** apArr, int size)
{
    for (int i = 0 ; i < size; i++)
    {
        apArr[i] =(Airport*) malloc(sizeof(Airport));
        if(!apArr[i])
            return 0;
        initAirport(apArr[i]);
    }
    return 1;
}

void freeAirport(Airport* apArr)
{
    free(apArr->name);

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
    printf("Airport name:%s                 Country:%s                     Code:%s\n", pAp->name, pAp->country, pAp->code);
}
void printAirportArr(const Airport** apArr, int size)
{
    for(int i = 0 ; i < size ; i++)
        printAirport(apArr[i]);
}