#include <stdio.h>
#include <string.h>
#define TAM_FRASE 100
#define TAM_PALAVRA 50

int conta(char *frase, char *palavra) {
    int contador = 0;

    char *token = strtok(frase, " ");

    while (token != NULL) {
        if (strcmp(token, palavra) == 0) contador++;
        token = strtok(NULL, " ");
    }

    return contador;
}
int main(){
    char frase[TAM_FRASE], palavra[TAM_FRASE];
    while (1)
    {
        printf("Frase? ");
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';
        if (strcmp(frase,".")==0) break;
        printf("Palavra? ");
        scanf("%s",palavra);
        printf("Resultado: A palavra %s apareceu %d vez na frase %s.\n", palavra, conta(frase, palavra),frase);
        while ((getchar()) != '\n');
    }

    return 0;
}