#include <stdio.h>
/* Count the number of occurrences of the 26 alphabets */
int main(void) {

	int c, i, j;
	int count[26];


	for( i = 0 ; i < 26 ; i ++ ) {
		count[i] = 0;
	}

	while ((c = getchar()) != '\n') {
		for (j=65; j<=90; j++) {
			if (c == j || c == j+32)
				count[j-65]++;
		}
	}

	for( i = 0 ; i < 26 ; i ++ ) {
		printf("%d ", count[i]);
	}
	printf("\n");
}