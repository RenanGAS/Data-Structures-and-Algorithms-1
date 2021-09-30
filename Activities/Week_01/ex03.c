#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *args[])
{
    double aAbs = atof(args[1]);
    double aAprox = atof(args[2]);
    double relatError;

    relatError = (fabs(aAbs - aAprox) / fabs(aAprox)) * 100;

    printf("\nDado o valor absoluto: %.10lf, e o valor aproximado: %.10lf :\n", aAbs, aAprox);
    printf("\n=> Temos que o Erro Relativo é de %.10lf%%\n\n", relatError);

    return 0;
}