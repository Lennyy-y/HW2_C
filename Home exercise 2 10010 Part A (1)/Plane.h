#ifndef __PLANE____
#define __PLANE____


typedef enum { Commercial,Cargo,Military,NumOfEnum } planeType;

static const char* planeTypes[NumOfEnum] = {"Commercial","Cargo","Military"};

typedef struct
{
    planeType type;
    int serialNum;

}Plane;

planeType getPlaneTypeFromUser();
void initPlane(Plane* pPl,Plane* pArr,int planeCount);
int isValidPlane(Plane* p);
void getPlaneSnum(Plane* pPl,Plane* pArr,int planeCount);
//int initPlaneArr(Plane** plArr, int size);
void printPlane(const Plane* pPl);
void printPlaneArr(const Plane** plArr, int size);
void freePlaneArr(Plane** plArr, int size);

#endif