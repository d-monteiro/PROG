#include <stdio.h>

int main(){

char c;
int linhas,colunas,i=0,j=0;    

printf("Introduza um carater: ");
scanf("%c",&c);
printf("Introduza o numero de linhas: ");
scanf("%d",&linhas);
printf("Introduza o numero de colunas: ");
scanf("%d",&colunas);

for ( j = 0; j < colunas; j++)
{
    printf("x");
}

printf("\n");

for ( i = 0; i < linhas-2; i++)
{
    printf("%c",c);

    for (j = 0; j < colunas-2; j++)
    {
        printf(" ");
    }
    
    printf("%c\n",c);
}

for ( j = 0; j < colunas; j++)
{
    printf("x");
}

printf("\n");

}