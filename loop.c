/*	

A C program that prompts the users to enter a number between 0 and 9. 
If the input is not valid, keep prompting for valid inputs for 5 times. 
After that, time-out and exit the program. Using the given valid n, 
prints all values between 2^0 and 2^n.	

*/

#include <stdio.h>
#define SIZE 10

int main(void) {

	int i = 5;
	int input, j, k;
	int lst[SIZE];

	for (j=0; j<SIZE; j++)     //initialize list
		lst[j] = 0;
	
	do {
		printf("Enter a number between 0 and 9: \n");
    	k = scanf("%d", &input);
        getchar();
        if(k == 1) {
            if(input >= 0 && input <= 9) {
                if(input == 0) {
                    lst[0] = 1;
                }
                else {
                    lst[0] = 1;
                    for (j=1; j<=input; j++) {
                    lst[j] = lst[j-1] * 2;
                    }
                }

            for(j=0; j<SIZE; j++)
                if(lst[j] != 0)
                    printf("%d\n", lst[j]);

            break;
            }
        }

    	i--;
	} 
	while (i>0);

	return 0;
}