#include <stdio.h>

float co2percapita(int pop,float co2){
    float emissoes=(co2*1000000)/pop;
    return emissoes;
}

int main(){
    int i,popp,popc,ano=0;
    float co2p,co2c;
    printf("ANO   PT   CN\n");
    for ( i = 2000; i <= 2020; i++)
    {
       scanf("%d %f %d %f",&popp,&co2p,&popc,&co2c);
       printf("%d  %.2f  %.2f\n",i,co2percapita(popp,co2p),co2percapita(popc,co2c));
       if (ano==0&&co2percapita(popp,co2p)<co2percapita(popc,co2c))
       {
        ano=i;
       }
    }
    printf("%d\n",ano);
}