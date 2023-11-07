#include <stdio.h>
#include <stdlib.h>

int main(){
    int r[30];
     for (int i = 0; i < 30; i++) {
        r[i]=(rand()%6)+1;
        printf("%d\n",r[i]);
    }
    printf("Histograma de 30 lançamentos:\n");
    for (int i = 1; i <=6 ; i++) {
        printf("%d - ", i );
        for (int j = 0; j < 30; j++) {
            if (r[j]==i)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}

