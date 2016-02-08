#include <stdio.h>

double inner_product(double *a, double *b, int n) {
    double result;
    for (int i=0; i<n; i++)
        result += a[i]*b[i];
    return result;
}

int main(void) {
    double v[] = {2.3, 6.0, 1.2, 0.7, 9.4, 5.1, 0.2, 4.4, 2.3, 0.01};
    printf("%f\n",inner_product(v,v,10));
    printf("Expected: 182.280100\n");
}