#include "Plane.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* planeTypes[NumOfEnum] = {"Travelers", "Luggage", "Military"};
int isValidPlane(Plane* p)
{
    if (!p->type || !p->serialNum)
        return 0;
    return 1;
}

void initPlane(Plane* pPl)
{
    pPl->type = getPlaneType();
    pPl->serialNum = serialCounter++;
}
int initPlaneArr(Plane** plArr, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        plArr[i] = malloc(sizeof(Plane));
        if(!plArr[i])
            return 0;
        initPlane(plArr[i]);
    }
    return 1;
}
planeType getPlaneType()
{
    int type;
    printf("Enter plane type\n");
    do {
        for (int i = 0; i < NumOfEnum; i++)
            printf("Enter %d for %s\n", i, planeTypes[i]);
        scanf("%d", &type);
    } while (type < 0 || type >= NumOfEnum);
    return (planeType)type;
}
void printPlane(const Plane* pPl)
{
    printf("Plane type: %s\nSerial number: %d\n", planeTypes[pPl->type], pPl->serialNum);
}
void printPlaneArr(const Plane** plArr, int size)
{
    for (int i = 0 ; i < size ; i++)
        printPlane(plArr[i]);
}
void freePlaneArr(Plane** plArr, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        free(plArr[i]);
    }
}