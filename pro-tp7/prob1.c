/*
    Implemente a função copia_pares com as seguintes características:
        - realiza o produto, elemento a elemento do  vetor 1 pelo vetor 2
        - tamanhos dos vetores de entrada são indicados nos parâmetros n1 e n2
        - o retorno da função deverá ser o tamanho do vetor de saída
        - a função deve verificar se o tamanho do vetor de entrada está 
          dentro dos limites (0 < n <= TAM_MAX); caso não esteja deve retornar -1
        - caso os vetores de entrada tenham tamanhos diferentes, o vetor de saída 
          deverá ter o tamanho do menor vetor de entrada

    Exemplo:
        vetor de entrada 1: { 4 7 6 }
        vetor de entrada 2: { 2 8 2 1 3}
        vetor de saída: { 8 56 12 }
*/

#include <stdio.h>

#define TAM_MAX 10

/********************************************/
/*       ALTERAR APENAS ESTA FUNCAO         */

int produto_vetores(int entrada1[], int n1, int entrada2[], int n2, int saida[])
{
    int n=0;
    if(n1>TAM_MAX || n2>TAM_MAX || n1<=0 || n2<=0){
        n=-1;
    }
    else{
        if(n1<n2){
            for(int i=0;i<n1;i++){
                saida[i]=entrada1[i]*entrada2[i];
                n=n1;
            }
        }
        else{
            for(int i=0;i<n2;i++){
                saida[i]=entrada1[i]*entrada2[i];
                n=n2;
            }
        }
    }
    return n;
}

/********************************************/

void imprime_vetor(int v[], int n);

int main()
{
    int v1[TAM_MAX] = { 4, 7, 6 };
    int v2[TAM_MAX] = { 2, 8, 2, 1, 3 };
    int res[TAM_MAX], tam;

    printf("vetor de entrada 1: ");
    imprime_vetor(v1, 3);
    printf("vetor de entrada 2: ");
    imprime_vetor(v2, 5);

    tam = produto_vetores(v1, 3, v2, 5, res);

    printf("vetor de saida: ");
    imprime_vetor(res, tam);
}

void imprime_vetor(int v[], int n)
{
    int i;
    printf("{");
    for(i=0; i<n; i++)
        printf(" %d", v[i]);
    printf(" }\n");
}