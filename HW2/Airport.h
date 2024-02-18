#pragma once
#include <string.h>
#define IATA_LEN 3
#define MAX_STR_LEN 255
typedef struct
{
    char* name;
    char* country;
    char code[IATA_LEN + 1];

}Airport;

int isSameAirport(void* ap1, void* ap2);
int isAirportCode(Airport* ap, char* IATA);
char* getAirportName();
void initAirport(Airport* pAp);
int initAirportArr(Airport** apArr, int size);
void freeAirportArr(Airport** apArr, int size);
void printAirport(const Airport* pAp);
void printAirportArr(const Airport** apArr, int size);