#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILMES 4000
#define TSIZE 150
#define CSIZE 30
#define MAXPAISES 20
#define DECADA_PESQUISA 1970
#define PAIS_PESQUISA "Poland"

typedef struct
{
    unsigned int id;
    char titulo[TSIZE];
    char origem[MAXPAISES][CSIZE];
    unsigned int ano, duracao;
} filme;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int maisLongo(filme catalogo[], int n)
{
    unsigned int temp=0;
    int num=0;

    for(int i; i<n; i++){
        if(catalogo[i].duracao>temp){
            temp=catalogo[i].duracao;
            num=i;
        }
    }

    return num;
}



int listaDecada(filme catalogo[], int n, int decada)
{
    int total=0;
    FILE *f;
    f=fopen("decada.txt","w");
    fprintf(f,"Informacao da decada %d (total = %d filmes)\n",decada,total);
    for(unsigned int i=decada; i<(decada+10); i++){
        int num=0;
        for(unsigned int j = 0; j<n; j++){
            if(catalogo[j].ano == i){
                num+=1;
            }
        }
        total+=num;
        fprintf(f,"%d - %d\n",i,num);
    }
    fclose(f);
    return total;
}


int pesquisaPorPais(filme catalogo[], int n, char *pais, filme resultado[])
{
    unsigned int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<CSIZE; j++){
            if(strcmp(catalogo[i].origem[j],pais)==0){
                memcpy(&resultado[k], &catalogo[i], sizeof(filme));
                k++;
            }
        }
    }

    for(int i=0; i<k; i++){
        for(int j=0; j<k-i; j++){
            if(resultado[j].duracao<resultado[j+1].duracao){
                filme temp=resultado[j];
                resultado[j]=resultado[j+1];
                resultado[j+1]=temp;
            }
        }
    }

    return k;
}



/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

int ler(char *filename, filme catalogo[]);

void listar(filme catalogo[], int n);

void imprimir(filme f);

int main()
{
    filme catalogo[MAXFILMES] = {0}, resultado[MAXFILMES];
    int nfilmes, nres, duracao;
    int posMax;
    
    nfilmes = ler("catalogo.txt", catalogo);
    printf("\n*** Filmes (%d) ***\n", nfilmes);
    listar(catalogo, nfilmes);
    printf("\n");

    posMax = maisLongo(catalogo, nfilmes);
    if (posMax != -1)
    {
        printf("\n*** Filme mais longo (duracao %d minutos) ***\n\n", catalogo[posMax].duracao);
        imprimir(catalogo[posMax]);
    }
    else
        printf("\n*** Filme mais longo (duracao -- minutos) ***\n\n---");
    printf("\n");

    printf("\nInformacao da decada %d (total = %d filmes)\n", DECADA_PESQUISA, listaDecada(catalogo, nfilmes, DECADA_PESQUISA));
    printf("\n");

    nres = pesquisaPorPais(catalogo, nfilmes, PAIS_PESQUISA, resultado);
    printf("\n*** Filmes com origem %s (%d) ***\n\n", PAIS_PESQUISA, nres);
    listar(resultado, nres);
    printf("\n");

    return 0;
}

int ler(char *filename, filme catalogo[])
{
    FILE *f;
    int n = 0;
    char linha[1000];
    char paises[MAXPAISES * CSIZE];

    f = fopen(filename, "r");
    if (f == NULL)
        return 0;

    while ((n < MAXFILMES) && fgets(linha, 1000, f) != NULL)
    {
        linha[strlen(linha) - 1] = '\0';
        catalogo[n].id = atoi(strtok(linha, "\t"));
        strcpy(catalogo[n].titulo, strtok(NULL, "\t"));
        strcpy(paises, strtok(NULL, "\t"));
        catalogo[n].ano = atoi(strtok(NULL, "\t"));
        catalogo[n].duracao = atoi(strtok(NULL, "\t"));

        int npaises = 0;
        char *pais;
        strcpy(catalogo[n].origem[0], strtok(paises, ","));
        while ((pais = strtok(NULL, ",")) != NULL)
            strcpy(catalogo[n].origem[npaises++], pais + 1);
        n++;
    }

    fclose(f);
    return n;
}

void listar(filme catalogo[], int n)
{
    int i, j;

    for (i = 0; i < 3 && i < n; i++)
    {
        imprimir(catalogo[i]);
    }
    if (n > 3)
    {
        if (n > 6)
            puts("...");
        j = i;
        if (n - 3 > j)
            j = n - 3;
        for (i = j; i < n; i++)
        {
            imprimir(catalogo[i]);
        }
    }
}

void imprimir(filme f)
{
    int i = 1;
    printf("%d - %s ", f.id, f.titulo);
    printf("| %s", f.origem[0]);
    while (strlen(f.origem[i]) != 0)
    {
        printf(", %s", f.origem[i]);
        i++;
    }
    printf(" | %d | %d\n", f.ano, f.duracao);
}