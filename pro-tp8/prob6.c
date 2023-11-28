#include <stdio.h>
#include <math.h>
/*
int fatorial(int n)
{
    if(n == 1)
        return 1;
    else
        return (n*fatorial(n-1));
}
*/
int factorial(int n)
{
    int result = 1, i;
 
    // loop from 2 to n to get the factorial
    for (i = 2; i <= n; i++) {
        result *= i;
    }
 
    return result;
}
float seno(float x){
    float seno=0,n=0;
    while(n<10){
        seno=seno+((pow(-1,n+1))*(pow(x,2*n-1)/factorial(2*n-1)));
        printf("%f\n",seno);
        n++;
    }
    return seno;
}

int main(){
    printf("%f\n",seno(1.57));
    printf("%d\n",factorial(5));
}