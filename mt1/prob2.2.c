#include <stdio.h>

float contribuicao(float n1,float n2){
    float c=(n2/n1)*100;
    return c;
}

int main(){
    printf("Contribuição da agricultura para as emissões de N2O :\n");
    float n1,n2,max_0=0,max_1=1000,s=0;
    int ano,i,anomax_0,anomax_1;
    for (i=0;i<=18;i++)
    {
        scanf("%d %f %f",&ano,&n1,&n2);
        //printf("%d %f %f-->",ano,n1,n2);
        printf("%d: %.1f%%\n",ano,contribuicao(n1,n2));
        s+=n1;                //s=s+n1
        //printf("%f\n",s);
        if (contribuicao(n1,n2)>max_0)
        {
            max_0=contribuicao(n1,n2);
            anomax_0=ano;
        }
        if (n1<max_1)
        {
            max_1=n1;
            anomax_1=ano;
        }
    }
    printf("Ano em que a agricultura mais contribuiu para as emissões de N2O per capita : %d\n",anomax_0);
    printf("Ano em que as emissões de N2O per capita foram mais reduzidas : %d\n",anomax_1);
    printf("Média das emissões de N2O per capita : %.3f\n",s/19);
}