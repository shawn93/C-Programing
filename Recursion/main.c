#include <stdio.h>

int main() {
    ascending(10);
    printf("\n");
    printf("Expected output is: 12345678910\n"); 
    int a[] = { 9, 2, 6, 7, 5, 4, 0, 2, 7, 5 }; 
    printf("%d \n",min(a, 2, 8));
    printf("Expected output is: 0\n");
    printf("%d \n",mul(2,8)); 
    printf("Expected output is: 16\n"); 
    printf("%d \n",mul(-2,8)); 
    printf("Expected output is: -16\n");
    printf("%d \n",mul(2,-8)); 
    printf("Expected output is: -16\n");
    printf("%d\n",mul(-2,-8)); 
    printf("Expected output is: 16\n");
    char email[] ="dai.yo.hhh@gmail.com"; 
    printf("%d \n",count(email,'.')); 
    printf("Expected output is: 3\n");
}
