#include <stdio.h>

 int divisao(int dividendo,int divisor,int quociente, int resto){
    if(divisor==0) return 0;
    else{
    int aux=dividendo,c=0;
        while(aux>0){
            aux-=divisor;
            c++;
        }
        resto=dividendo-(c*divisor);
        quociente=c;
    }
    return -1;
 }

 int main(){
    int q,r,a;
    a=divisao(5,2,q,r);
    printf("quociente:%d\nresto:%d\nreturn:%d\n",q,r,a);
 }