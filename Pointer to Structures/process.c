#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct entry* process_quotes(char* quotes, struct entry* head) {
	struct entry* newNode = (struct entry*) malloc(sizeof(struct entry));
	newNode->quote = quotes;
	newNode->count = strlen(quotes);
	if (head == NULL) {
		head = newNode;
		head->next = NULL;
		// For debug
		// printf("head\n");
	}
	//head != NULL
	else {
		if (newNode->count < head->count) {
			newNode->next = head;
			head = newNode;	
			// For debug
			// printf("insert at head\n");
			return head;
		}
		else {
			if ((newNode->count > head->count) && head->next == NULL) {
				head->next = newNode;
				newNode->next = NULL;
				// For debug
				// printf("linsert at last && head->next is null\n");
				return head;
			}
			if ((newNode->count == head->count) && head->next == NULL) {
				//duplication
				if (strcmp(newNode->quote,head->quote) == 0) {
					// For debug
					// printf("=\n");
					return head;
				}
				else {
					head->next = newNode;
					newNode->next = NULL;
					// For debug
					// printf("=\n");
					return head;
					}
				}
			//head->next != NULL
			if (head->next != NULL) {
				struct entry* currNode = (struct entry*) malloc(sizeof(struct entry));
				currNode = head->next;
				if ((newNode->count > head->count)  && (newNode->count < currNode->count)) {
						newNode->next = currNode;
						head->next = newNode;
						// For debug
						// printf("insert at mid\n");
						return head;
					}
				while (currNode->next != NULL) {
					//duplication
					if (newNode->count == currNode->count) {
						if (strcmp(newNode->quote,currNode->quote) == 0) {
							// For debug
							// printf("=\n");
							return head;
						}
						else {
							newNode->next = currNode->next;
							currNode->next = newNode;
							// For debug
							// printf("==\n");
							return head;
						}
					}
					if ((newNode->count > currNode->count) && (currNode->next != NULL) && (newNode->count < currNode->next->count)) {
						newNode->next = currNode->next;
						currNode->next = newNode;
						// For Debug
						// printf("insert at mid\n");
						return head;
					}
					currNode = currNode->next;
				}	
				if(currNode->count < newNode->count && currNode->next == NULL) {
					// For Debug
					// printf("insert at last******\n");
					currNode->next = newNode;
					newNode->next = NULL;
					return head;
				}
			}				
		}		
	}
	return head;
}