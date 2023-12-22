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
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
            if(statsJogadores[i].pts>temp){ 
                temp=statsJogadores[i].pts;
                *mvPlayer=statsJogadores[i];
            }
        }
        return temp;
    }
    else return -1;
}