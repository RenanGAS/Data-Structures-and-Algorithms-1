#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *v, int tam)
{
    int i;
    printf("[");
    for (i = 0; i < tam; i++)
    {
        printf("%d", v[i]);
        if (i < tam - 1)
        {
            printf(",");
        }
    }
    printf("]");
    printf("\n");
}

// exercício 01

int *criarVetor(int tam, int val)
{
    int i;
    int *vet = (int *)calloc(tam, 4);
    for (i = 0; i < tam; i++)
    {
        vet[i] = val;
    }
    return vet;
}

// exercício 02

// exercício 03

// exercício 04

// exercício 05

// exercício 06

// exercício 07

int main()
{

    imprimirVetor(criarVetor(4, 4), 4);

    return 0;
}