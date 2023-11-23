#include <stdio.h>

int divisao (int dividendo, int divisor, int *quociente, int *resto);

int main (){
    int dividendo, divisor, *quociente, *resto, resultado;

    printf ("Digite o dividendo :");
    scanf ("%d", &dividendo);

    printf ("Digite o divisor: ");
    scanf ("%d", &divisor);

    resultado = divisao (dividendo, divisor, *quociente, *resto);

    if (resultado == 0) {
        printf ("O divisor não deve ser zero. \n");
    } 
    else {
        printf("Quociente: %d\n", *quociente);
        printf("Resto: %d\n",*resto);
    }
    return 0;
}

int divisao (int dividendo, int divisor, int *quociente, int *resto){
        if (divisor != 0) {
        int c = 0, dividendo_2 = dividendo;
        while (dividendo_2 >= divisor) {
            dividendo_2 -= divisor;
            c++;
        }
        *resto = dividendo - (c * divisor);
        *quociente = c;
        return -1;
        }
        else
        {
        return 0; 
      }
}