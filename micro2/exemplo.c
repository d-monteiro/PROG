int copia_pares(int entrada[], int n, int saida[])
{
    int t=0;
    if(n<=TAM_MAX && n>0){
        for(int i=0; i<n; i++){
            if(entrada[i]%2==0 && entrada[i]!=0){
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