#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSTR 15
#define MAXV 25
#define EURO_KM 0.10

float lat_origem=41.14961, lon_origem=-8.61099;

float haversine(float lat1, float lon1, float lat2, float lon2);

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int leViagens(char cidades[][MAXSTR], float latitudes[], float longitudes[], int portagens[])
{
    int i = 0;
    while (scanf("%s %f %f %d", cidades[i], &latitudes[i], &longitudes[i], &portagens[i]) != EOF) i++;
    return i;
}
/*
{
    int i=0;
    char cidade[MAXV][MAXSTR]={0};
    while (scanf("%s %f %f %d",cidade[i],&latitudes[i],&longitudes[i],&portagens[i])!=EOF)
    {
        if (strlen(cidade[i])>MAXSTR)
        {
            strcpy(cidades[i],"Inválido");
        }
        else strcpy(cidades[i],cidade[i]);
        i++;
    }

    return i;
}
*/

void calculaCustos(char cidades[][MAXSTR], float latitudes[], float longitudes[], int portagens[], int n, int *maisBarato, float *custoFinal)
{
    float distancia[MAXV];
    float custototal[MAXV];
    for (int i = 0; i < n; i++)
    {
        distancia[i]=haversine(lat_origem,lon_origem,latitudes[i],longitudes[i]);
        custototal[i]=(distancia[i]*EURO_KM)+portagens[i];
    }
    *custoFinal=custototal[0];
    for (int j = 1; j < n; j++)
    {
        if (custototal[j]<custototal[j-1])
        {
            *custoFinal=custototal[j];
            *maisBarato=j;
        }
        
    }
    
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/ 

int main() 
{
    char cidades[MAXV][MAXSTR]={0};
    float latitudes[MAXV] = {0};
    float longitudes[MAXV] = {0};
    int portagens[MAXV] = {0};
    int n=0;

    n = leViagens(cidades, latitudes, longitudes, portagens);
    if(n > 0)
    {
        printf("\nForam processadas %d cidades\n", n);
        for(int i = 0; i < n; i++)
        {
            printf("Cidade: %s. %d euros. Coordenadas (%f, %f)\n", cidades[i], portagens[i], latitudes[i], longitudes[i]);
        }
    }
    else {
        printf("\nForam processadas 0 cidades\n\n");
        return 1;
    }
    
    int maisBarato = 0;
    float custoFinal;
    calculaCustos(cidades, latitudes, longitudes, portagens, n, &maisBarato, &custoFinal);

    printf ("\nA cidade mais barata para viajar é %s, com custo de %.2f euros\n\n", cidades[maisBarato], custoFinal);

    return 0;
}

// Calcula a distancia entre dois pontos
float haversine(float lat1, float lon1, float lat2, float lon2)
{
    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLon = (lon2 - lon1) * M_PI  / 180.0;
 
    // Converte para radianos
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
 
    // Formula de Haversine
    float a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}