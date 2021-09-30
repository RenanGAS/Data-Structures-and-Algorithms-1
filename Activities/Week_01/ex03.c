#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *args[])
{
    // Enviar dois argumentos: um valor exato e um aproximado (Ex. 3 e 2.7777)

    double aEx = atof(args[1]);
    double aAprox = atof(args[2]);
    double relatError = 0;

    relatError = (fabs(aEx - aAprox) / fabs(aAprox)) * 100;

    printf("\nDado o valor exato: %.10lf, e o valor aproximado: %.10lf :\n", aEx, aAprox);
    printf("\n=> Temos que o Erro Relativo é de %.10lf%%\n\n", relatError);

    return 0;
}