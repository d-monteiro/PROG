#include <stdio.h>

int contem(int a,int b){
    while (a>0)
    {
        
        if (a%10==b%10)
        {
            b/=10; 
            a/=10;
            if (b == 0) {
                return 1;
            }
        }
        else {
            a/=10;
        }    
    }
    return 0;
}

int main(){
    int u,a,b,n,d;
    printf("Introduza um numero: ");
    scanf("%d",&a);
    printf("Introduza um segundo numero: ");
    scanf("%d",&b);
   
    if (contem(a, b)) {
        printf("%d está contido em %d.\n", b, a);
    } else {
        printf("%d não está contido em %d.\n", b, a);
    }
}