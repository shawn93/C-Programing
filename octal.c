#include <stdio.h>
#define SIZE 5
/* Read an integer entered by the user and displays it in octal */
int main(void) {

	int input,i;
	int num[SIZE];

	printf("Enter a number between 0 and 32767:\n");
    scanf("%d", &input);

    for (i=0; i<5; i++) {    	
    	num[4-i] = input % 8;
    	input = input / 8;
    }

    printf("The entered number in octal is:\n");

    for (i=0; i<SIZE; i++)
    	printf("%d", num[i]);
    printf("\n");
}