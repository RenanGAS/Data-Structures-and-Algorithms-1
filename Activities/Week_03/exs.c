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

int *criarVetorAleatorio(int tam, int maxVal)
{
    int i;
    int *v = (int *)calloc(tam, sizeof(int));
    for (i = 0; i < tam; i++)
    {
        v[i] = (rand() % maxVal) + 1;
    }
    return v;
}

// exercício 04

void incrementaVetor(int *v, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] += 1;
    }
}

// exercício 05

// exercício 06

// exercício 07

int main()
{
    int testV[6] = {1, 2, 3, 4, 5, 6};

    printf("\nTeste do exercício 1:\n");
    imprimirVetor(criarVetor(3, 1), 3);

    printf("\nTeste do exercício 2:\n");
    imprimirVetor(clonarVetor(testV, 6), 6);

    printf("\nTeste do exercício 03:\n");
    imprimirVetor(criarVetorAleatorio(5, 100), 5);

    printf("\nTeste do exercício 04:\n");
    incrementaVetor(testV, 6);
    imprimirVetor(testV, 6);

    return 0;
}