#include <stdio.h>
#include <stdlib.h>
int aleatorio(int limiteInferior, int limiteSuperior) {
    int random;
    random = (rand() % ((limiteSuperior+1)-limiteInferior))+limiteInferior;
    return random;
}
int main () {
    int inf=0,sup=0,n=0,s=0;
    printf("Quantos lançamentos:");
    scanf(" %d",&n);
    printf("Defina o limite inferior:");
    scanf(" %d",&inf);
    printf("Defina o limite superior:");
    scanf(" %d",&sup);
    while (n>0) {
        int i=aleatorio(inf,sup);
        /*printf("%d\n",i);*/
        if (i==4)
        {
            s+=1;
        }
        n=n-1;
    }
    printf("A face quatro saiu %d vezes.\n",s);
}










