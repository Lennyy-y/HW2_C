#include "Date.h"
#include <stdio.h>


int isDateValid(Date* d)
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
void getCorrectDate(Date* pD)
{
    while(1)
    {
        char date[MAX_INPUT_SIZE + 1] = {0};
        printf("Enter Flight Date dd##mm##yyyy  minimum year 2023\n");
        scanf("%s", date);
        sscanf(date, "%d##%d##%d", &pD->day, &pD->month, &pD->year);
        if(!isDateValid(pD))
        {
            printf("Error try again\n");
            continue;
        }
        break;
    }    
        
}
void printDate(const Date* pD)
{
    printf("Date: %d / %d / %d\n", pD->day, pD->month, pD->year);
}
