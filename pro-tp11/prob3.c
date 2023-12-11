#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 1000
#define TSIZE 10
#define NSIZE 50
#define TOP 10

typedef struct{
    char nome[NSIZE];
    char nomeEquipa[TSIZE];
    int jogos;
    float min, pts;
} jogador;

/** 
 *  @brief  Determinar o jogador com melhor média de pontos marcados.
 *  @param  statsJogadores array de jogadores
 *  @param  n número de jogadores em 'statsJogadores'
 *  @param  mvPlayer apontador para jogador com a melhor média de pontos marcados
 *  @return Melhor média de pontos marcados ou -1 em caso de erro
 *  @note   Deve ser verificado se o valor de 'n' é válido (superior a zero).
 */
float mvp(jogador statsJogadores[], int n, jogador *mvPlayer)
{
    float temp=0;
    if (n>0)
    {
        for (int i = 0; i < n; i++)
        {
            if (statsJogadores[i].pts>temp){
                temp=statsJogadores[i].pts;
                *mvPlayer=statsJogadores[i];
            }
        }
        return temp;
    }
    else return -1;
}

/** 
 *  @brief  Armazenar a informação dos jogadores de determinada equipa.
 *  @param  statsJogadores array de jogadores
 *  @param  n número de jogadores em 'statsJogadores'
 *  @param  equipa equipa à qual os jogadores devem pertencer
 *  @param  nomeFicheiro nome do ficheiro onde a informação deve ser gravada
 *  @return Número de jogadores gravados ou -1 em caso de erro
 *  @note   Deve ser verificado se o valor de 'n' é válido (superior a zero) e se os nomes da equipa e do ficheiro são strings vazias.
 */
int gravaEstatisticas(jogador statsJogadores[], int n, char *equipa, char *nomeFicheiro)
{
    int num=0;
    if (n>0 || (strlen(equipa)==0) || (strlen(nomeFicheiro)==0))
    {
        FILE *f;
        f=fopen(nomeFicheiro,"w");
        for (int i = 0; i < n; i++)
        {
            if (strcmp(statsJogadores[i].nomeEquipa,equipa)==0)
            {
                fprintf(f,"%s\t",statsJogadores[i].nome);
                fprintf(f,"%s\t",statsJogadores[i].nomeEquipa);
                fprintf(f,"%d\t",statsJogadores[i].jogos);
                fprintf(f,"%f\t",statsJogadores[i].min);
                fprintf(f,"%f",statsJogadores[i].pts);
                fprintf(f,"\n");
                num++;
            }  
        }
        fclose(f);
        return num;
    }
    else return -1;
}

/** 
 *  @brief  Determinar os jogadores com melhor média de pontos marcados.
 *  @param  statsJogadores array de jogadores
 *  @param  n número de jogadores em 'statsJogadores'
 *  @param  topValue número de jogadores a pertencer ao top
 *  @param  topJogadores array ordenado dos 'topValue' melhores jogadores
 *  @return 0 em caso de sucesso ou -1 em caso de erro
 *  @note   Deve ser verificado se os valores de 'n' e 'topValue' são válidos (superiores a zero).
 *  @note   'topValue' deve ser inferior ou igual a 'n'.
 */
void top10Jogadores(jogador statsJogadores[], int n, jogador topJogadores[])
{
    jogador copy[MAXP];
    memcpy(copy,statsJogadores,n*sizeof(jogador));
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (copy[j].pts>copy[j+1].pts){
                jogador temp=copy[j];
                copy[j]=copy[j+1];
                copy[j+1]=temp;
            }
        }
    }
    for (int k = 0; k < 10; k++)
    {
        topJogadores[k]=statsJogadores[k];
    }
    
}

/*
 * ***** NAO ALTERAR ESTE CODIGO ****
 * */

int lerJogadores(char *filename, jogador statsJogadores[]);

void listarJogadores(jogador statsJogadores[], int n);

void imprimirJogador(jogador pl);

int main(){
    jogador statsJogadores[MAXP], topJogadores[10], mvPlayer;
	int njogadores;
    float pontos;

	njogadores = lerJogadores("nbaStats.txt", statsJogadores);
	printf("\n*** Jogadores (%d) ***\n", njogadores);
	listarJogadores(statsJogadores, njogadores);
	printf("\n");

    pontos = mvp(statsJogadores, njogadores, &mvPlayer);
	printf("\n*** Most Valuable Player (media de pontos %.1f) ***\n\n", pontos);
    if(pontos)
        imprimirJogador(mvPlayer);
	printf("\n");

    printf("\n*** A gravar jogadores da equipa %s para o ficheiro statsJogadores.txt ***\n", "GSW");
    printf("\nInformacao de %d jogadores gravada com sucesso\n", gravaEstatisticas(statsJogadores, njogadores, "GSW", "statsJogadores.txt"));
	printf("\n");

	top10Jogadores(statsJogadores, njogadores, topJogadores);
	printf("\n*** Top 10 jogadores (media de pontos) ***\n\n");
    listarJogadores(topJogadores, 10);
	printf("\n");

	return 0;
}

int lerJogadores(char *filename, jogador statsJogadores[]){
	FILE * f;
	int njogadores = 0;
    char name[NSIZE];

    f = fopen("nbaStats.txt", "r");
    if(f == NULL)
		return 0;

	while((njogadores < MAXP) && (fscanf(f, "%s %s %s %d %f %f", 
        statsJogadores[njogadores].nome, name, statsJogadores[njogadores].nomeEquipa,
        &(statsJogadores[njogadores].jogos), &(statsJogadores[njogadores].min),
        &(statsJogadores[njogadores].pts)) != EOF)){

        strcat(statsJogadores[njogadores].nome, " ");
        strcat(statsJogadores[njogadores].nome, name);
        njogadores++;
    }

    fclose(f);

    return njogadores;
}

void listarJogadores(jogador statsJogadores[], int n)
{
    int i, j;
    
    for (i = 0; i < 3 && i < n; i++) imprimirJogador(statsJogadores[i]);
    if (n > 3) {
        if (n > 6) puts("...");
        j = i;
        if (n - 3 > j) j = n - 3;
        for (i = j; i < n; i++) imprimirJogador(statsJogadores[i]);
    }
}

void imprimirJogador(jogador pl)
{
    printf("%-22s %-5s %2d %6.1f %6.1f\n", pl.nome, pl.nomeEquipa, pl.jogos, pl.min, pl.pts);
}
