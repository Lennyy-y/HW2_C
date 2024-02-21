#include "Plane.h"
#include <stdio.h>
#include <stdlib.h>

planeType getPlaneTypeFromUser()
{
	int temp;
	do {
		printf("Please enter one of the following types\n");
		for (int i = 0; i < NumOfEnum; i++)
			printf("%d for %s\n", i, planeTypes[i]);
		scanf("%d", &temp);
	} while (temp < 0 || temp >= NumOfEnum);
	return (planeType) temp;
}

int isValidPlane(Plane* p)
{
    if (!p->type || !p->serialNum)
        return 0;
    return 1;
}

void getPlaneSnum(Plane* pPl,Plane* pArr,int planeCount)
{
    int goBack;
    while(1)
    {
        printf("Enter plane serial number - between 1 to 9999 \n");
        scanf("%d", &pPl->serialNum);
        if( pPl->serialNum < 1 || pPl->serialNum > 9999)
            continue;
        if(planeCount != 0)
            for ( int i = 0; i < planeCount; i++)
            {
                if ( pPl->serialNum == pArr[i].serialNum )
                {
                    printf("The serial number u wanted for this plane is not available \n");
                    goBack = 1;
                    break;
                }
            }
        if(goBack == 1)
            continue;
        break;

    }
}
void initPlane(Plane* pPl,Plane* pArr,int planeCount)
{
    getPlaneSnum(pPl,pArr,planeCount) ;
    pPl->type =getPlaneTypeFromUser();
    printf("check1");
}
//int initPlaneArr(Plane** plArr, int size)
//{
//  for (int i = 0 ; i < size ; i++)
//   {
//         plArr[i] = malloc(sizeof(Plane));
//         if(!plArr[i])
//             return 0;
//         initPlane(plArr[i],plArr,size);
//     }
//    return 1;
// }


void printPlane(const Plane* pPl)
{
    printf("Plane: serial number:%d, type %s \n", planeTypes[pPl->type], pPl->serialNum);
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