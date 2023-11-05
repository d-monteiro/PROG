#include <stdio.h>
int contador(long n, int d){
    int v=0;
    while (n!=0)
    {
        int u=n%10;
        //printf("%d\n",u);
        if (u==d)
        {v++;}
        n/=10;
        //printf("%ld\n",n);
    }
    return v;
}
int main(){
    long n;
    int d;
    printf("Introduza um número inteiro: ");
    scanf("%ld",&n);
    printf("Introduza um dígito: ");
    scanf("%d",&d);
    printf("O digito %d aparece %d vezes no número %ld\n",d,contador(n,d),n);
}

/*
n= número introduzido
d= dígito pretendido
v= vezes que aparece o dígito pretendido
u= último dígito do número
n%10 isola o último digito
v++ incrementa o nº de vezes
n/=10 retira o último dígito após a contagem
*/