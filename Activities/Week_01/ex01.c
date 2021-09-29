#include <stdio.h>

int main()
{
    int varInt;
    int varInt1;
    unsigned int sum;

    printf("\nDigite um número inteiro positivo: ");     // Sugestão: 2147483647
    scanf("%d", &varInt);

    printf("\nDigite outro número inteiro positivo: ");     // Sugestão: 2147483647
    scanf("%d", &varInt1);

    sum = varInt + varInt1;
    printf("\n=> %d + %d = %u\n\n", varInt, varInt1, sum);

    return 0;
}