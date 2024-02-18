#pragma once

typedef enum {
    Travelers,Luggage,Military,NumOfEnum
    } planeType;
static int serialCounter = 1000;
typedef struct
{
    planeType type;
    int serialNum;
}Plane;
const char* planeTypes[NumOfEnum];

int isValidPlane(Plane* p);
void initPlane(Plane* pPl);
int initPlaneArr(Plane** plArr, int size);
planeType getPlaneType();
void printPlane(const Plane* pPl);
void printPlaneArr(const Plane** plArr, int size);
void freePlaneArr(Plane** plArr, int size);