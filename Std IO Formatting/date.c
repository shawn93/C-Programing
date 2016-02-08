#include <stdio.h>

int is_Valid(int month, int day, int year) {
	int result = 0;
	if (year >0) {
		if (month == 2) {
			if (((year%4 == 0 && year%100 != 0)|| year%400 == 0) && day > 0 && day <= 29) {
				result = 1;
			}
			else if (((year%4 != 0 && year%100 != 0)|| year%400 != 0) && day > 0 && day <= 28) {
				result = 1;
			}
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day>0 && day <= 31) {
				result = 1;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day>0 && day <=30) {
				result = 1;
			}
		}		
	} 
	return result;
}

int main() {
	int mon, day, year, input;
	char a,b;	//determine '-' or '/'
	char *month[12];
	month[0] = "January";
	month[1] = "February";
	month[2] = "March";
	month[3] = "April";
	month[4] = "May";
	month[5] = "June";
	month[6] = "July";
	month[7] = "August";
	month[8] = "September";
	month[9] = "Octorber";
	month[10] = "November";
	month[11] = "December";
	printf("Enter a date in the format month-day-year or month/day/year: \n");
	input = scanf("%d%c%d%c%d", &mon, &a, &day, &b, &year);
	if (((a == '-' && b == '-') && input == 5 && is_Valid(mon, day, year)) || ((a == '/' && b == '/') && input == 5 && is_Valid(mon, day, year))) {
		printf("%s %d, %d\n", month[mon-1], day, year);	
	}
	else {
		printf("Date not Valid.\n");
	}		
}