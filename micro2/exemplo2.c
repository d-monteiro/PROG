int compacta(int entrada[], int n, int saida[])
{
    int t=0;
    if(n>0 && n<=TAM_MAX){
        saida[t]=entrada[0];
        t++;
        for(int i=1;i<n;i++){
            if(entrada[i]!=entrada[i-1]){
                saida[t]=entrada[i];
                t++;
            }
            else{
                ;
            }
        }
    }
    else{
        t=0;
    }
    return t;
}