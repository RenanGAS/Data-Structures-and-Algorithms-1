#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *v, int tam)
{
    int i;
    printf("\n");
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
    printf("\n\n");
}

// exercício 01

int *criarVetor(int tam, int val)
{
    int i;
    int *vet = (int *)calloc(tam, sizeof(int));
    for (i = 0; i < tam; i++)
    {
        vet[i] = val;
    }
    return vet;
}

// exercício 02

int *clonarVetor(int *v, int tam)
{
    int i;
    int *cloneV = (int *)calloc(tam, sizeof(int));

    for (i = 0; i < tam; i++)
    {
        cloneV[i] = v[i];
    }
    return cloneV;
}

// exercício 03

// exercício 04

// exercício 05

// exercício 06

// exercício 07

int main()
{
    printf("\nTeste do exercício 1:\n");
    imprimirVetor(criarVetor(3, 1), 3);

    printf("\nTeste do exercício 2:\n");
    imprimirVetor(clonarVetor(criarVetor(4, 2), 4), 4);

    return 0;
}