#include <stdio.h>
int n1,n2;
int main() {
    printf(" Numero inteiro 1? ");
    scanf("%d", &n1);
    printf(" Numero inteiro 2? ");
    scanf("%d", &n2);
    if (n1%n2==0)
    {
       printf("%d e multiplo de %d\n", n1,n2); 
    }
    else
    {
        printf("%d nao e multiplo de %d\n", n1,n2); 
    }
    return 0;
}