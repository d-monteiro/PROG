#include <stdio.h>
int diferença(int exp,int exv) {
     int dif = exp-exv;
     return dif;
}
int main () {


int i, exp, exv, ano, anomenex, anodifo ;
long menex = 1000000000, difo = 1;
for (i=0; i<=19; i++){
    scanf ("%d %d %d", &ano, &exp, &exv);
    printf ("Diferença em %d : %d\n",ano, diferença(exp, exv));

    if (exp<menex) {
        menex = exp;
        anomenex = ano;
    }

    if (diferença(exp, exv)>difo){
        difo = diferença(exp, exv);
        anodifo = ano;
    }

    printf ("Ano em que foram produzidos menos exemplares: %d\n", anomenex);
    printf ("Ano em a diferença entre produzidos e vendidos foi maior: %d\n", anodifo);
}
return 0;
}