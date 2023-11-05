#include <stdio.h>
#include <math.h>
int main() {
    int a,b,c,x1,x2;
    printf("Quadratic equation solver\n");
    printf("In the form of ax2+bx+c\n");
    printf("Enter integer a\n");
    scanf("%d",&a);
    printf("Enter integer b\n");
    scanf("%d",&b);
    printf("Enter integer c\n");
    scanf("%d",&c);
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    printf("The solutions are: %d  &  %d\n", x1,x2);

    return 0;
 }