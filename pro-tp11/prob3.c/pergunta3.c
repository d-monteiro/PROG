void back_prop(int, size_t, jogador*);
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
int topJogadores(jogador statsJogadores[], int n, int topValue, jogador top[])
{
    if (n <= 0 || topValue <= 0 || topValue > n)
        return -1;
        
    for (size_t i = 0; i < n; ++i)
        top[i] = statsJogadores[i];
        
    for (size_t i = 0; i < n - 1; ++i)
        if (top[i+1].pts > top[i].pts) 
            back_prop(n, i+1, top);
            
    return 0;
}

void back_prop(int n, size_t i, jogador* top){
    jogador buff;
    for (size_t j = 0; j < i; ++j)
        if (top[i].pts > top[j].pts) {
            buff = top[j];
            top[j] = top[i];
            top[i] = buff;
        }
}