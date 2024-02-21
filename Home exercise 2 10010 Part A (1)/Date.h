#ifndef __DATE____
#define __DATE____

typedef struct
{
    int day;
    int month;
    int year;
}Date;
int isDateValid(Date* d);
void getCorrectDate(Date* pD);
void printDate(const Date* pD);

#endif