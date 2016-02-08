#include <stdio.h>

int mul(int a, int b) {

	if(a > 0 && b >0) {
		if(a == 0)
			return 0;
		return b + mul(a-1, b);
	}
	else if(a > 0 && b <0) {
		if(a == 0)
			return 0;
		return b + mul(a-1, b);

	}
	else if(a < 0 && b >0) {
		if(b == 0)
			return 0;
		return a + mul(a, b-1);

	}
	else {
		if(a == 0)
			return 0;
		return -b + mul(a+1,b);
	}
}