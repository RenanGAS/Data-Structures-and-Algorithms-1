#include "vector_TAD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector
{
    int *vet;
    int tam;
    int qtd;
};

Vector *vet_concatena(Vector *v1, Vector *v2)
{
    int tam_vet = v1->qtd + v2->qtd;

    Vector *new_vector = (Vector *)malloc(sizeof(Vector));
    int *new_vet = (int *)malloc(tam_vet * sizeof(int));
    new_vector->vet = new_vet;
    new_vector->tam = tam_vet;
    new_vector->qtd = 0;

    int countV1 = 0;
    int countV2 = 0;

    for (int i = 0; i < tam_vet; i++)
    {
        if (countV1 < v1->qtd)
        {
            new_vet[i] = v1->vet[countV1];
            countV1++;
        }
        else
        {
            new_vet[i] = v2->vet[countV2];
            countV2++;
        }

        new_vector->qtd += 1;
    }

    return new_vector;
}

Vector *vet_intercala(Vector *v1, Vector *v2)
{
    int tam_vet = v1->qtd + v2->qtd;

    Vector *new_vector = (Vector *)malloc(sizeof(Vector));
    int *new_vet = (int *)malloc(tam_vet * sizeof(int));
    new_vector->vet = new_vet;
    new_vector->tam = tam_vet;
    new_vector->qtd = 0;

    int countV1 = 0;
    int countV2 = 0;

    for (int i = 0; i < tam_vet; i++)
    {
        if (((v1->vet[countV1] < v2->vet[countV2]) && countV1 < v1->qtd) || countV2 >= v2->qtd)
        {
            new_vet[i] = v1->vet[countV1];
            countV1++;
        }
        else
        {
            new_vet[i] = v2->vet[countV2];
            countV2++;
        }

        new_vector->qtd += 1;
    }

    return new_vector;
}
