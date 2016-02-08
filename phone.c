#include <stdio.h>
#define SIZE 20
/* Check the telephone number is in the correct format */
int main(void) {

    char str[SIZE];         //to store the input 
    printf("Enter Phone Number:  (xxx)xxx-xxxx\n");
    scanf("%s",str);

    if (str[0] == '(' && str[4] == ')' && str[8] == '-' && str[13] == 0 && str[1] >='0' && str[1] <= '9' && str[2] >='0' && str[2] <= '9' && str[3] >='0' && str[3] <= '9' && str[5] >='0' && str[5] <= '9' && str[6] >='0' && str[6] <= '9' && str[7] >='0' && str[7] <= '9' && str[9] >='0' && str[9] <= '9' && str[10] >='0' && str[10] <= '9' && str[11] >='0' && str[11] <= '9' && str[12] >='0' && str[12] <= '9')
        printf("The phone number is %c%c%c.%c%c%c.%c%c%c%c\n", str[1], str[2], str[3], str[5], str[6], str[7], str[9], str[10], str[11], str[12]);
    else
        printf("The phone number is invalid.\n");    

}