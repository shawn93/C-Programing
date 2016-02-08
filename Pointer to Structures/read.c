#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAXCHARS 100

char* read_quotes() {
	printf("Enter a quote or Q to quit: ");
	char* quote = (char *) malloc(sizeof (char)* MAXCHARS);
	char buffer[200];
	int length;
	fgets(buffer, 200, stdin);
	length = strlen(buffer);
	if (length<=MAXCHARS && length!=0)
		strcpy(quote,buffer);
	return quote;
}