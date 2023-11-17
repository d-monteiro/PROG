#include <stdio.h>

 int divisao(int dividendo,int divisor,int *quociente, int *resto){
    if(divisor!=0){
    int c=0,aux=dividendo;
        while(aux>=divisor){
            aux-=divisor;
            c++;
        }
        *resto=dividendo-(c * divisor);
        *quociente=c;
        return -1;
    }
    else return 0;
 }

 int main(){
    int q,r,a;   
    a=divisao(7,2,&q,&r);
    printf("Teste 1/4-\nquociente:%d\nresto:%d\nreturn:%d\n\n",q,r,a);

    a=divisao(7,0,&q,&r);
    printf("Teste 2/4-\nquociente:%d\nresto:%d\nreturn:%d\n\n",q,r,a);

    a=divisao(6,2,&q,&r);
    printf("Teste 3/4-\nquociente:%d\nresto:%d\nreturn:%d\n\n",q,r,a);

    a=divisao(81937,74,&q,&r);
    printf("Teste 4/4-\nquociente:%d\nresto:%d\nreturn:%d\n\n",q,r,a);

 }