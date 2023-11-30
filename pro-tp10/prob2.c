#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 40      /* Máximo número de caracteres da string */
#define MAX_COMPR 100   /* Máximo número de caracteres a ler */
#define MAX_PRODS 100   /* Máximo número de artigos no armazém */

/* Registo para um artigo do armazém */
typedef struct {
    char nome[MAX_TAM];     /* Designação do artigo */
    char marca[MAX_TAM];    /* Marca do artigo */
    char modelo[MAX_TAM];   /* Modelo do artigo */
    float preco;            /* Preço do artigo */
    int quant;              /* Quantidade disponível */
} artigo;

/** 
 *  @brief  Preencher o armazém, lendo o conteúdo de um ficheiro de texto.
 *  @param  armazem array de artigos a preeencher
 *  @return Número de artigos lidos
 *  @note   Cada linha do ficheiro corresponde a um artigo e tem o seguinte formato:
 *          nome marca modelo preco quant
 */
int leArtigos(artigo armazem[])
{
    int n=0, result;
    while((result=scanf("%s %s %s %f %d", armazem[n].nome,armazem[n].marca,armazem[n].modelo,
    &armazem[n].preco, &armazem[n].quant))!=EOF)
    {
        n++;
    }
    return n;
}

/** 
 *  @brief  Calcular o número de artigos de determinada marca e modelo.
 *  @param  armazem array de artigos
 *  @param  n número de artigos em 'armazem'
 *  @param  marca marca dos artigos a procurar
 *  @param  modelo modelo dos artigos a procurar
 *  @return Número de artigos de determinada marca e modelo
 */
int totalArtigos(artigo armazem[], int n, char *marca, char *modelo)
{
    int num=0;
    for(int i=0;i<n;i++){
        if(strcmp(armazem[i].marca, marca) == 0 && strcmp(armazem[i].modelo, modelo) == 0){
            num=armazem[i].quant;
        }
    }
    return num;
}

/** 
 *  @brief  Listar os artigos com stock inferior a determinado valor.
 *  @param  armazem array de artigos
 *  @param  n número de artigos em 'armazem'
 *  @param  stock_lim limite para a quantidade dos artigos a procurar
 *  @return void
 *  @note   Imprime os artigos de stock inferior ao parâmetro 'stock_lim' no seguinte formato: quant\tnome marca modelo.
 */
void alertaArtigos(artigo armazem[], int n, int stock_lim)
{
    for(int i=0;i<n;i++){
        if(armazem[i].quant < stock_lim){
            printf("%d\t%s %s %s\n",armazem[i].quant, armazem[i].nome ,armazem[i].marca, armazem[i].modelo);
        }
    }
}

/** 
 *  @brief  Ordenar os artigos pela sua quantidade.
 *  @param  armazem array de artigos
 *  @param  n número de artigos em 'armazem'
 *  @return void
 *  @note   Imprime os artigos em stock ordenados no seguinte formato: quant\tnome marca modelo.
 */
void ordenaArtigos(artigo armazem[], int n)
{
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (armazem[j].quant>armazem[j+1].quant){
                artigo temp=armazem[j];
                armazem[j]=armazem[j+1];
                armazem[j+1]=temp;
            }
        }
    }
    printf("Produtos em stock (ordenados):\n");
    for (int i=0;i<n;i++){
        printf("%d\t%s %s %s\n",armazem[i].quant, armazem[i].nome ,armazem[i].marca, armazem[i].modelo);
    }
}

int main()
{
    artigo storage[MAX_PRODS];
    int lim = 10, n_prod = 0;

    n_prod = leArtigos(storage);
    printf("Produtos:\n");
    for (int i = 0; i < n_prod; i++) printf("- %s %s %s | %d | %.2f€\n", storage[i].nome, storage[i].marca, storage[i].modelo, storage[i].quant, storage[i].preco);
    printf("TOTAL: %d\n", n_prod);

    printf("\nHá %d artigo(s) da marca %s e modelo %s.\n", totalArtigos(storage,n_prod,"Grapple","10.2"),"Grapple","10.2");
    
    printf("\nArtigos com stock inferior a %d unidades:\n", lim);
    alertaArtigos(storage, n_prod, lim);

    printf("\n");

    ordenaArtigos(storage, n_prod);
    return 0;
}