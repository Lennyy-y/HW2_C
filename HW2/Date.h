#pragma once

typedef struct
{
    int day;
    int month;
    int year;
}Date;
int isValidDate(Date* d);
void initDate(Date* pD);
void printDate(const Date* pD);