#include <stdio.h>
#include "header.h"

void print_result(struct entry* node) {
    printf("In Sorted Order:\n");
    while (node != NULL) {
        printf("%s", node->quote);
        node = node->next;
    }
}