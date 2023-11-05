#include <stdio.h>
#define pi 3.1416

double n,p,a;
int main() {
    printf("Raio?");
    scanf("%lf", &n);
    p=2*pi*n;
    a=pi*n*n;
    printf("Perimetro = %.4lf\n", p);
    printf("Area = %.4lf\n", a);
    return 0;
}