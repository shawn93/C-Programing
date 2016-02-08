#include <stdio.h>

int min(int a[], int start, int end) {
	if(start == end)
		return a[start];
	else
		return (a[end] < min(a,start,end-1)) ? a[end] : min(a,start,end-1);
}