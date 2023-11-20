#include <stdio.h>
void contaVezes(int num, int dig,int *ptr_vezes){
    int v=0;
    while (num!=0)
    {
        int u=num%10;
        //printf("%d\n",u);
        if (u==dig) v++;
        num/=10;
        //printf("%d\n",n);
    }
    *ptr_vezes=v;
}
int main(){
    int num;
    int dig;
    int *vezes;
    printf("Introduza um número inteiro: ");
    scanf("%d",&num);
    printf("Introduza um dígito: ");
    scanf("%d",&dig);
    contaVezes(num,dig,&vezes);
    printf("O digito %d aparece %d vezes no número %d\n",dig,vezes,num);
}

/*
num= número introduzido
dig= dígito pretendido
v= vezes que aparece o dígito pretendido
u= último dígito do número
num%10 isola o último digito
v++ incrementa o nº de vezes
num/=10 retira o último dígito após a contagem
*/