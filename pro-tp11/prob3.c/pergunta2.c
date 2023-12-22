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
    int counter = 0;
    FILE* fptr;
    if (n <= 0 || nomeFicheiro[0] == '\0' || equipa[0] == '\0'){
        return -1;
    }
    fptr = fopen(nomeFicheiro, "w");
    if (fptr == NULL){
        return -1;
    }
    for (int i = 0; i < n; ++i){
        if (!strcmp(statsJogadores[i].nomeEquipa, equipa)) {
            fprintf(fptr, "%s %s %d %f %f\n", statsJogadores[i].nome, statsJogadores[i].nomeEquipa, statsJogadores[i].jogos, statsJogadores[i].min, statsJogadores[i].pts); 
            counter++;
        }
    }
    fclose(fptr);
    return counter;
}