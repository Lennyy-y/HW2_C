#ifndef ___AIRPORT___
#define ___AIRPORT___


#include <string.h>
#define IATA_LEN 3
#define MAX_STR_LEN 255
typedef struct
{
    char* name;
    char country[MAX_STR_LEN];
    char code[IATA_LEN + 1];

}Airport;

int isSameAirport(void* ap1, void* ap2);
int isAirportCode(Airport* ap, char* IATA);
void getAirportName(Airport* ap);
void  getAirportCountry(Airport* pAp);
void getAirportCode(char* code);
void initAirport(Airport* pAp);
void initAirportNoCode(Airport* pAp);
int initAirportArr(Airport** apArr, int size);
void freeAirport(Airport* apArr);
void freeAirportArr(Airport** apArr, int size);
void printAirport(const Airport* pAp);
void printAirportArr(const Airport** apArr, int size);

#endif