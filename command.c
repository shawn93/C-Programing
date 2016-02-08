#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
	int i;
	int result;

	if(strcmp(argv[1],"-a") == 0 && argc > 2) {
		result = atoi(argv[2]);
		for(i = 3; i<argc; i++) {
			result += atoi(argv[i]);			
		}
		printf("%d\n", result);
	}

	if(strcmp(argv[1],"-s") == 0 && argc > 2) {
		result = atoi(argv[2]);
		for(i = 3; i<argc; i++) {
			result -= atoi(argv[i]);			
		}
		printf("%d\n", result);
	}

	if(strcmp(argv[1],"-m") == 0 && argc > 2) {
		result = atoi(argv[2]);
		for(i = 3; i<argc; i++) {
			result *= atoi(argv[i]);			
		}
		printf("%d\n", result);
	}
}