#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define MAXENTRY 50
#define MAXCHARS 100

struct entry* head = NULL;

void free_mem(struct entry* a)
{
  if(a->next == NULL) 
    return;
  else
    {
      free_mem(a->next);
      free(a->next);
    }
  return;
}

int main(void) {
	int i=0;
	while (i<MAXENTRY) {
		char* quote = (char *) malloc(sizeof (char)* MAXCHARS);
		quote = read_quotes();
		if (quote[0]=='Q' && strlen(quote) == 2) {
			break;
		}
		if (strcmp(quote,"\n") != 0) {		//Ignore newline
			head = process_quotes(quote,head);
			i++; //50 times
		}

		free(quote);
	}

	printf("\n");
	if (head != NULL) {
		print_result(head);
		//For Debug
		// printf("head*****%s\n", head->quote);
	}
	else {
		printf("No quote.\n");
	}
	free_mem(head);
}