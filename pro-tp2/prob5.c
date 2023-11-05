#include <stdio.h>

int main() {
    double numero;
    printf("Digite um numero decimal: ");
    scanf("%lf", &numero);
    int parteInteira = (int)numero;
    double parteDecimal = numero - parteInteira;
    printf("Numero com 3 casas decimais = %.3lf\n", numero);
    printf("Parte Inteira = %d\n", parteInteira);
    printf("Parte Decimal = %.3lf\n", parteDecimal);
    return 0;
}