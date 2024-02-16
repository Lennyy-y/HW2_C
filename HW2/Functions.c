#include "Functions.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void trimWhiteSpace(char* str)
{
    size_t len = 0;
    char *leftPointer = str;
    char *rightPointer = NULL;

    len = strlen(str);
    rightPointer = str + len;

    while( isspace((unsigned char) *leftPointer) ) // remove the left whitespace
    {
        ++leftPointer;
    }
    if(rightPointer != leftPointer )
    {
        rightPointer--; // skip the null terminate byte ('/0')
        while(isspace((unsigned char) *(rightPointer)) && rightPointer != leftPointer ) // remove the right whitespace
        {
            rightPointer--;
        }
    }

    if(leftPointer != str && rightPointer == leftPointer ) //if everything is a whitespace then the null terminate will be at the first address
        *str = '\0';
    else if( str + len - 1 != rightPointer ) //move the null terminate to the end of the trimmed string
        *(rightPointer + 1) = '\0';

    rightPointer = str; // moving the string to the address of str so that we can still free the memory with the same pointer
    if(leftPointer != str )
    {
        while( *leftPointer )
        {
            *rightPointer++ = *leftPointer++;
        }
        *rightPointer = '\0';
    }
}


void capitalizeFirstLetters(char* str)
{
    for (int i = 0 ; i < strlen(str) ; i++)
    {
        if (i == 0)
        {
            if(*(str + i) >= 'a' && *(str +i) <= 'z')
                *(str + i) -= 32; // subtract 32 to get the uppercase letter
        }
        if (isspace((unsigned char) *(str + i) )) {
            i++;
            if(*(str + i) >= 'a' && *(str +i) <= 'z')
                *(str + i) -= 32; // subtract 32 to get the uppercase letter
        }
    }
}

void numOfWords(char* str)
{
    int spaceCounter = 0; // count the occurrences of space
    int spaceIndices[strlen(str)]; // save the index of all space characters to avoid going through the whole array twice
    char* endPointer = str + strlen(str);
    int length;
    for (int i = 0 ; i < strlen(str) ; i++)
    {
        if(str[i] == ' ')
        {
            spaceIndices[spaceCounter] = i + spaceCounter;
            spaceCounter++;
        }
    }
    if(!spaceCounter) //if the string is only one word
    {
        for(int i = 1 ; (*(str + i) != '\0' || *(str + i + 1) != '\0') ; i+=2) // stopping condition depends on whether the string length is even or odd
        {
            length = (int)(endPointer - str);
            memmove(str + i + 1, str + i, length - i + 1);
            endPointer++;
            *(str + i) = '_';
        }
    }

    else if (spaceCounter % 2 == 1) { // if there is an odd number of spaces there's an even number of words
        for (int i = 0 ; i < spaceCounter ; i++)
        {
            length = (int)(endPointer - str);
            memmove(str + spaceIndices[i] * sizeof(char) + 1, str + spaceIndices[i] * sizeof(char), length - spaceIndices[i] + 1); // move the string 1 byte forward starting from the place where there's a space
            endPointer++;
            *(str+spaceIndices[i]) = ' ';
        }
    }
}