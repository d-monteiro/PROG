#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSTRING 50
#define MAXREG 1000
#define LIMITE1  35.0
#define LIMITE2  25.0
#define FICHEIRO "populacao.txt"

typedef struct{
    char nome[MAXSTRING];
    char regiao[MAXSTRING];
    float altura;
    float peso;
} pessoa;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

float calcPercentagem(pessoa *pv, int n, char *regiao, float limite, char *nomeFicheiro)
{
    float count=0;
    float total=0;
    float IMC[MAXREG];
    for (int i = 0; i < n; i++)
    {
        IMC[i]=(pv[i].peso/((pv[i].altura/100)*(pv[i].altura/100)));
    }
    if(nomeFicheiro!=NULL)
    {
        FILE *f;
        f=fopen(nomeFicheiro,"w");
        for (int i = 0; i < n; i++)
        {
            if (strcmp(pv[i].regiao,regiao)==0)
            {
                total++;
                if (IMC[i]>limite)
                {
                    fprintf(f,"%s | %.1f | %.1f\n", pv[i].nome, pv[i].altura, pv[i].peso);
                    count++;
                }
            }
        }
        fclose(f);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (strcmp(pv[i].regiao,regiao)==0)
            {
                total++;
                if (IMC[i]>limite) count++;
            }
        }
    }
    float Percentagem=(count/total)*100;
    return Percentagem;
}

/****************************************************/

float calcMediana(pessoa *pv, int n)
{
    float mediana=0;
    float h[MAXREG];
    for (int i = 0; i < n-1; i++) h[i]=pv[i].altura;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (h[j]>h[j+1]){
                float temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        } 
    }

    if (n%2==0) mediana=(h[n/2]+h[n/2+1])/2.0;
    else mediana=h[n/2];

    return mediana;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/ 

int lerEntrada(char *ficheiro, pessoa *pv, int n);
void imprimePessoas(const pessoa v[], int n );

int main()
{
    pessoa pv[MAXREG]={0};
    int   n=0;
    float media=0.0, mediana;
    char *pesquisa1 = "North West";
    char *pesquisa2 = "London";

    n = lerEntrada(FICHEIRO, pv, MAXREG);
    //printf("\nEntradas lidas=%d\n", n);
    //imprimePessoas(pv, n);

    media = calcPercentagem(pv, n, pesquisa1, LIMITE1, "resultado.txt");
    printf("\nPercentagem IMC>%.1f (%s) = %.0f%%\n", LIMITE1, pesquisa1, media);

    media = calcPercentagem(pv, n, pesquisa2, LIMITE2, NULL);
    printf("Percentagem IMC>%.1f (%s) = %.0f%%\n", LIMITE2, pesquisa2, media);

    mediana = calcMediana(pv, n);
    printf("\nMediana Altura = %.1f\n\n", mediana);
}

int lerEntrada(char *ficheiro, pessoa *pv, int n)
{
    FILE *f;
    const char *sep = ";";
    char *token;
    char linha[200]={0};
    int linec=0;
    
    f = fopen(ficheiro, "r");
    if(f==NULL){
        return -1;
    }

    while(fgets(linha, sizeof(linha), f) !=NULL)
    {
        if(linec>n) {
            fclose(f);
            return -1;
        }

        token = strtok(linha, sep);
        strcpy(pv[linec].nome, token);
        token = strtok(NULL, sep);
        strcpy(pv[linec].regiao, token);
        token = strtok(NULL, sep);
        pv[linec].altura= atof(token);
        token = strtok(NULL, sep);
        pv[linec].peso= atof(token);
        linec++;
    }
    fclose(f);
    return linec;
}

void imprimePessoas(const pessoa v[], int n){
    int iter = 0;
    printf("Pessoas na lista:\n");
    for(iter=0; iter<2;iter++){
        printf("%18s | %25s | %.1f | %.1f\n", \
            v[iter].nome, v[iter].regiao, v[iter].altura, v[iter].peso);
    }
    iter = n-1;
    printf("\t(...)\n%18s | %25s | %.1f | %.1f\n", \
            v[iter].nome, v[iter].regiao, v[iter].altura, v[iter].peso);
}