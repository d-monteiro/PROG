#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 80      /* Máximo número de caracteres da string */
#define MAX_COMPR 200   /* Máximo número de caracteres a ler */
#define MAX_LIVROS 50   /* Máximo número de livros */

/* Registo para um livro */
typedef struct {
    char titulo[MAX_TAM];   /* Título do livro */
    char autor[MAX_TAM];    /* Autor do livro */
    char lingua[MAX_TAM];   /* Língua do livro */
    int ano;                /* Ano do livro */
} livro;

/** 
 *  @brief  Preencher a base de dados, lendo o conteúdo de um ficheiro de texto.
 *  @param  lista array de livros a preeencher
 *  @return Número de livros na base de dados
 *  @note   Cada linha do ficheiro corresponde a um livro e tem o seguinte formato:
 *          titulo|autor|ano|lingua
 */
int registarLivros(livro lista[])
{
    int n = 0;
    char temp[MAX_TAM];
    while (n<MAX_LIVROS && fgets(temp, MAX_TAM, stdin)!=NULL) {
        temp[strcspn(temp, "\n")] = '\0';

        char *token=strtok(temp,"|");
        if (token!=NULL) strcpy(lista[n].titulo, token);

        token=strtok(NULL,"|");
        if (token!=NULL) strcpy(lista[n].autor, token);

        token = strtok(NULL,"|");
        if (token!=NULL) lista[n].ano=atoi(token);

        token = strtok(NULL,"|");
        if (token!=NULL) strcpy(lista[n].lingua, token);

        n++;
    }

    return n;
}

/** 
 *  @brief  Ordenar os livros por ordem alfabética do título.
 *  @param  lista array de livros
 *  @param  n número de livros em 'lista'
 *  @param  lista_ord array de livros ordenados por ordem alfabética
 *  @return 0 em caso de sucesso ou -1 em caso de erro.
 *  @note   Deve ser verificado se o valor de 'n' é válido (superior a zero).
 */
int ordenaLivros(livro lista[], int n, livro lista_ord[])
{
    if (n>0)
    {
        memcpy(lista_ord, lista, n * sizeof(livro));
        for (int i=0;i<n-1;i++){
            for (int j=0;j<n-i-1;j++){
                if (strcmp(lista_ord[j].titulo,lista_ord[j+1].titulo)>0){
                    livro temp=lista_ord[j];
                    lista_ord[j]=lista_ord[j+1];
                    lista_ord[j+1]=temp;
                }
            }
        }
        return 0;
    }
    else return -1;
}

/** 
 *  @brief  Calcular o número de livros publicados a partir de determinado ano.
 *  @param  lista array de livros
 *  @param  n número de livros em 'lista'
 *  @param  ano ano a partir do qual se pretende verificar quantos livros foram publicados
 *  @return Número de livros publicados a partir do ano 'ano' (inclusive). Em caso de erro, retorna -1.
 *  @note   Deve ser verificado se os valores de 'n' e 'ano' são válidos (superiores a zero).
 */
int publicados(livro lista[], int n, int ano)
{
    int num=0;
    if (n>0 && ano>0)
    {
        for (int i = 0; i < n; i++)
        {
            if (lista[i].ano>=ano) num++; 
        }
        return num;
    }
    else return -1; 
}

/** 
 *  @brief  Selecionar os livros cuja primeira letra do nome do autor se encontra entre dois caracteres.
 *  @param  lista array de livros
 *  @param  n número de livros em 'lista'
 *  @param  c1 caracter (letra minúscula)
 *  @param  c2 caracter (letra minúscula)
 *  @param  lista_selec array de livros cuja primeira letra do nome do autor se encontra entre 'c1' e 'c2'
 *  @return Número de livros selecionados. Em caso de erro, retorna -1.
 *  @note   Deve ser verificado se o valor de 'n' é válido (superior a zero).
 *  @note   Os valores de 'c1' e 'c2' devem ser válidos (entre a e z e 'c2' < 'c1').
 *  @note   No caso de 'c1' ser igual a 'c2', deve ser calculado o número de livros cuja primeira letra do nome do autor é igual a 'c1'.
 */
int selecionaLivros(livro lista[], int n, char c1, char c2, livro lista_selec[])
{
    int num=0;
    if ((n>0 && c1>='a' && c1<='z' && c2>='a' && c2<='z') && (c1<c2 || c1==c2))
    {
        for (int i = 0; i < n; i++)
        {
            if (lista[i].autor[0]>=toupper(c1) && lista[i].autor[0]<=toupper(c2))
            {
                lista_selec[num]=lista[i];
                num++;
            }
        }
        return num;
    }
    else return -1;
}

/** 
 *  @brief  Listar os livros de uma base de dados.
 *  @param  lista array de livros
 *  @param  n número de livros em 'lista'
 *  @return void
 */
void imprimirLivros(livro lista[], int n)
{
    printf("Ano     |  Língua  |  Autor\t\t\t|  Título\n");
    for (int i = 0; i < 105; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) printf("%-7d |  %-7s |  %-25s |  %s\n", lista[i].ano, lista[i].lingua, lista[i].autor, lista[i].titulo);
}

int main()
{
    livro db[MAX_LIVROS], db_sort[MAX_LIVROS], db_selec[MAX_LIVROS];
    int n_liv = 0, ano_lim = 2002, n_selec = 0;
    char c_low = 'd', c_up = 'd';

    n_liv = registarLivros(db);
    printf("\n");
    imprimirLivros(db, n_liv);
    printf("\nTOTAL: %d\n", n_liv);

    ordenaLivros(db, n_liv, db_sort);
    printf("\n> Livros ordenados por título <\n");
    imprimirLivros(db_sort, n_liv);

    printf("\nHá %d livro(s) publicados a partir de %d.\n", publicados(db, n_liv, ano_lim), ano_lim);

    n_selec = selecionaLivros(db, n_liv, c_low, c_up, db_selec);
    printf("\nHá %d livro(s) cujo autor se encontra entre %c e %c.\n", n_selec, toupper(c_low), toupper(c_up));
    imprimirLivros(db_selec, n_selec);

    printf("\n");

    return 0;
}