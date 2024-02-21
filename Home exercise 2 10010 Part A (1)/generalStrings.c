#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "generalStrings.h"


char* getStrExactLength(const char* msg)
{
	char* theStr = NULL;
	size_t len;
	char inpStr[MAX_LENGTH]; //variable to hold the string that the user gives

	//Ask for a string from the user
	puts(msg);
	myGets(inpStr, sizeof(inpStr));
	theStr = strdup(inpStr);
	return theStr;
}


char* myGets(char* buffer, int size)
{
	char* ok;
	if (buffer != NULL && size > 0)
	{
		do {
			ok = fgets(buffer, size, stdin);
		} while (ok && ((strlen(buffer) <= 1) && (isspace(buffer[0]))));
		if (ok)
		{
			char* back = buffer + strlen(buffer);
			//trim end spaces
			while (isspace(*--back));
			*(back + 1) = '\0';
			return buffer;
		}
		buffer[0] = '\0';
	}
	return NULL;
}