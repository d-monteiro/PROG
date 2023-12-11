#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TENTATIVAS 6
#define MAX 100

void imprimeForca(int erros);
void carregaPalavras(char *ficheiro, char palavras[][MAX], int *tamanho);
void obfuscaPalavra(char* palavra, char *nova);
int letraNaPalavra(char a, char* palavra);
void revelaLetras(char letra, char *palavra, char *obfuscada);
int vencedor(char *p1, char *p2);
int joga(char *palavra, char *palavra_obfuscada);

int main()
{
	char *dados = "palavras.txt";
	char palavras[100][MAX];
	char palavra[MAX], palavra_obfuscada[MAX];
	int i, tamanho, contador;

	srand(time(NULL));

	 carregaPalavras(dados, palavras, &tamanho);
	if(tamanho != 0)
	{
		strcpy( palavra, palavras[rand()%tamanho]);
		obfuscaPalavra(palavra, palavra_obfuscada);

		printf("%s\n", palavra_obfuscada);
		contador = joga(palavra,palavra_obfuscada);
		if(contador < TENTATIVAS)
			printf("Parabens!\n");
		else
			printf("Game over... The word was %s\n",palavra);

	}

	return 0;
}

void imprimeForca(int erros)
{
	if (erros == 0)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 1)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 2)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	 |   |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 3)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	/|   |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 4)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	/|\\  |\n");
		printf ("	     |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 5)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	/|\\  |\n");
		printf ("	/    |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}
	else if (erros == 6)
	{
		printf ("	+------+\n");
		printf ("	 |   |\n");
		printf ("	 o   |\n");
		printf ("	/|\\  |\n");
		printf ("	/ \\  |\n");
		printf ("	     |\n");
		printf ("	============\n");
	}

}

void carregaPalavras(char *ficheiro, char palavras[][MAX], int *tamanho)
{
	int i=0;
	FILE *f;
	f=fopen(ficheiro,"r");
	while (fscanf(f, "%s", palavras[i]) == 1) i++;
	fclose(f);
	*tamanho=i;
}

void obfuscaPalavra(char* palavra, char *nova)
{
	int i = 0;

	strcpy(nova,palavra);
	while ( nova[i] != '\0' )
	{
		nova[i] = '*';
		i++;
	}
}

int letraNaPalavra(char a, char* palavra)
{
	int i = 0;
	while ( palavra[i] != '\0' )
	{
		if ( palavra[i] == a )
			return 1;
		i++;
	}
	return 0;
}

void revelaLetras(char letra, char *palavra, char *obfuscada)
{
	int comprimento=strlen(palavra);
    for (int i = 0; i < comprimento; i++) {
        if (palavra[i]==letra) obfuscada[i]=letra;
    }
}

int vencedor(char *p1, char *p2)
{
	if(strcmp(p1,p2)==0)
		return 1;
	else
		return 0;
}

int joga(char *palavra, char *palavra_obfuscada)
{
	char letra;
	int contador=0, erros=0, a=0;
	while (vencedor(palavra,palavra_obfuscada)==0)
	{
		if (a==0) imprimeForca(0);
	    printf("Digite uma letra: ");
    	scanf(" %c",&letra);
		revelaLetras(letra,palavra,palavra_obfuscada);
		if (letraNaPalavra(letra,palavra)==0)
		{
			erros++;
			imprimeForca(erros);
			contador++;
		}
		printf("%s\n",palavra_obfuscada);
		if (contador>=6) break;
		a++;
	}
	
    return contador;
}
