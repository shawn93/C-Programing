#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define swap_m(t, x, y) {t z; z = x; x=y; y=z;} 
/*
tests:
Before Swap_f:
x = 1  y = 0
After Swap_f:
x = 0  y = 1

Before Swap_m:
x = 0  y = 1
After Swap_m:
x = 1  y = 0

Swap_f running time:
Wed Sep 23 21:34:22 PDT 2015
Wed Sep 23 21:34:30 PDT 2015
Swap_m running time:
Wed Sep 23 21:34:30 PDT 2015
Wed Sep 23 21:34:35 PDT 2015
*/

/*
By comparing running time of those two kinds of implementations, 
Swap_m is less than Swap_f. In conclusion, Swap_m spend less time 
than Swap_f so Swap_m is more efficient than the Swap_f.
*/

void swap_f(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(){

	int x = 1, y = 0;
	//Swap_f test
	printf("Before Swap_f:\n");
	printf("x = %d  y = %d\n", x, y);
	swap_f(&x,&y);
	printf("After Swap_f:\n");
	printf("x = %d  y = %d\n", x, y);
	printf("\n");
	//Swap_m test
	printf("Before Swap_m:\n");
	printf("x = %d  y = %d\n", x, y);
	swap_m(int, x, y);
	printf("After Swap_m:\n");
	printf("x = %d  y = %d\n", x, y);
	printf("\n");
	//Swap_f running time
	printf("Swap_f running time:\n");
	system("date");
	for(int i=0; i<INT_MAX; i++) {
		swap_f(&x,&y); 
	}
	system("date");

	//Swap_m running time
	printf("Swap_m running time:\n");
	system("date");
	for(int i=0; i<INT_MAX; i++) {
		swap_m(int, x, y);
	}
	system("date");
}