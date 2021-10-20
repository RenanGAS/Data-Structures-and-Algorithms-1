#include <stdio.h>

// Exercício 1

int sumElem1(int *v, int tam)
{
    int sum = 0;

    for (int i = 0; i < tam; i++)
    {
        sum += v[i];
    }

    return sum;
}

void sumElem2(int *v, int tam, int *s)
{
    int sum = 0;

    for (int i = 0; i < tam; i++)
    {
        sum += v[i];
    }

    *s = sum;
}

int main()
{
    int vet[5] = {1, 2, 3, 4, 5};

    printf("\nTestes do exercício 1:\n");
    int sum1 = sumElem1(vet, 5);
    printf("\n=> Usando return: %d\n", sum1);
    int sum2 = 0;
    sumElem2(vet, 5, &sum2);
    printf("\n=> Usando a estratégia do scanf: %d\n", sum2);

    return 0;
}