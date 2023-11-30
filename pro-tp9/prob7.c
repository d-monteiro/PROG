#include <stdio.h>
#include <string.h>
void inverte(char *strOriginal, char *strInvertida){
    int n=strlen(strOriginal);
    printf("%d",n);
    for(int i=0;i<n;i++){
        strInvertida[n-i-1]=strOriginal[i];
        printf("%c\n",strInvertida[i]);
    }
}

int main() {
    char strOriginal[100];
    char strInvertida[100];

    fgets(strOriginal,100,stdin);

    strOriginal[strcspn(strOriginal, "\n")] = '\0';

    inverte(strOriginal, strInvertida);

    printf("A frase invertida e \"%s\".\n", strInvertida);

    return 0;
}