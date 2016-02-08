#include <stdio.h>

int count(char s[], char c) {
	if (s[0] == '\0') {
		return 0;		
	}
	if( s[0] == c) {
		return 1 + count(++s,c);
	}
	else {
		return 0 + count(++s,c);
	}
}