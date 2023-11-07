#include <stdio.h>

int contaRepeticao(int v[], int tamanhoVetor, int numero){
    int conta=0;
    for(int i = 0; i < tamanhoVetor; i++){
        if (v[i]==numero) conta++;
    }
    return conta;
}

int main(){
    int n,numero,v[100],i=0;
    while(1){
        printf("Introduza um numero:");
        scanf("%d",&n);
        if (n<0)  break;
        v[i]=n;
        i++;
    }
    printf("Numero a pesquisar:");
    scanf("%d",&numero);
    printf("Maior sequencia com numeros %d tem tamanho %d\n",numero,contaRepeticao(v,i+1,numero));
    return 0;
}
