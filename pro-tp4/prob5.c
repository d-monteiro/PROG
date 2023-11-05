#include <stdio.h>
#include <math.h>
/*compilar com -lm(clang/gcc prob5.c -lm)*/

double Ca(double Ci,double j,int anos){
    double C;
    C = Ci * pow((1 + j / 100), anos);
    return C;
}

int main() {
    double Ci, j;
    int anos;

    printf("Qual o capital inicial?\n");
    scanf("%lf", &Ci);

    printf("Qual a taxa de juro anual a ser aplicada?\n");
    scanf("%lf", &j);

    printf("Durante quantos anos?\n");
    scanf("%d", &anos);

    printf("O capital acumulado ao fim de %d anos é de %.3lf anos.\n", anos, Ca(Ci,j,anos));

    return 0;
}