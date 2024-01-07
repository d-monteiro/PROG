#include <stdio.h>
#include <string.h>

#define TSIZE 50
#define MAXATLETAS 36
#define DISTMAX 10.0
#define DESCONTO 7.0

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/* Guarda nomes completos dos atletas no vetor de strings nomes e as suas 
 * pontuacoes na mesma posicao no vetor distancia.
 * Retorna o numero de atletas lidos.
 * Nota: a informacao da origem e’ lida, mas nao guardada. 
 */
int lerAtletas(char nomes[][TSIZE], float distancia[])
{   
    int numAtletas = 0;
    char origem[TSIZE], nome1[TSIZE], nome2[TSIZE];
    float dist;
    while (scanf("%s", origem) != EOF) {


        if (strcmp(origem, "Galia") == 0){
            scanf("%s %f", nome1, &distancia[numAtletas]);
            strcpy(nomes[numAtletas],nome1);
        }
        else {
            scanf("%s %s %f", nome1, nome2, &distancia[numAtletas]);
            strcpy(nomes[numAtletas],nome1);
            strcat(nomes[numAtletas]," ");
            strcat(nomes[numAtletas],nome2);
        }
        numAtletas++;
    }
    for (int i = 0; i < numAtletas; i++)
    {
        printf("%s\n",nomes[i]);
        //printf("%f\n",distancia[i]);
    }
    

    return numAtletas;
}


/* Identifica quais sao os atletas romanos infratores (>10m) e 
 * penaliza em 7 metros a distancia desses atletas.
 * Retorna numero de correcoes feitas.
 */
int corrigeTabela(char nomes[][TSIZE], float distancia[], int nAtleta)
{
    int count=0;
    for (int i = 0; i < nAtleta; i++)
    {
        if (strchr(nomes[i],' ')!=NULL && distancia[i]>=10)
        {
            distancia[i]=distancia[i]-7;
            count++;
        }
    }
    
    return count;
}



/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

void imprimePontuacoes(float distancias[], int n);

int main()
{
    char nomes[MAXATLETAS][TSIZE];
    float distancias[MAXATLETAS];
    int nAtletas, nCorrigidos;

    nAtletas = lerAtletas(nomes, distancias);
    printf("Numero de atletas lidos: %d\n", nAtletas);

    nCorrigidos = corrigeTabela(nomes, distancias, nAtletas);
    printf("Numero de valores corrigidos: %d\n", nCorrigidos);
    printf("Vetor corrigido:\n");
    imprimePontuacoes(distancias, nAtletas);

    return 0;
}

void imprimePontuacoes(float distancias[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        if ((2 * i + 1) == MAXATLETAS)
            printf("\n");
        printf("%2.1f ", distancias[i]);
    }
    printf("\n");
}