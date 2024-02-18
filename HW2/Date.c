#include "Date.h"
#include <stdio.h>
#include "generalStrings.h"

int isValidDate(Date* d)
{
    if (d->day < 0)
        return 0;
    switch (d->month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
           if (d->day > 31)
               return 0;
           break;
        case 4: case 6: case 9: case 11:
           if (d->day > 30)
               return 0;
           break;
        case 2:
           if (d->day > 28)
               return 0;
           break;
        default:
               return 0;

   }
   if (d->year < 2023)
       return 0;
   return 1;
}
#define MAX_INPUT_SIZE 12
#define SEPARATOR '##'
void initDate(Date* pD)
{
    do {
        char date[MAX_INPUT_SIZE + 1] = {0};
        printf("Enter date in dd##mm##yyyy format\n");
        myGets(date, MAX_INPUT_SIZE + 1);
        sscanf(date, "%d##%d##%d", &pD->day, &pD->month, &pD->year);
    }
    while(!isValidDate(pD));
}
void printDate(const Date* pD)
{
    printf("Date: %d / %d / %d\n", pD->day, pD->month, pD->year);
}
