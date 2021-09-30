#include <stdio.h>

int main()
{
    float x0 = 1.31;
    float y0 = 3.24;
    float x1 = 1.93;
    float y1 = 4.76;

    float method1 = ((x0 * y1) / (y1 - y0)) - ((x1 * y0) / (y1 - y0)); // - preciso por realizar mais operações (7)
    float method2 = x0 - (((x1 - x0) * y0) / (y1 - y0));               // + preciso por realizar menos operações (5)

    printf("\n=> Resultado do método 1 = %.10f\n\n=> Resultado do método 2 = %.10f\n\n", method1, method2);

    return 0;
}