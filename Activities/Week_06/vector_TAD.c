#include "vector_TAD.h"
#include <stdlib.h>

struct vector
{
    int *vet;
    int tam;
    int qtd;
};

Vector *create_vector()
{
    Vector *newVector = (Vector *)calloc(4, sizeof(int));
    return newVector;
}

int length_vector(Vector *v)
{
    for (size_t i = 0; i < v->tam; i++)
    {
        /* code */
    }
    
}

void free_vector(Vector **endVector)
{
    free(*endVector);
    *endVector = NULL;
}

bool addIn_vector(Vector *v, int elemento)
{
    int lenVector = length_vector(v);
    if (v->vet[lenVector - 1] == 0)
    {
        v->vet[lenVector - 1] = elemento;
        return true;
    }
    else
    {
        free_vector(&v);
        v = (Vector *)calloc(2, lenVector);
        return false;
    }
}

bool putIn_vector(Vector *v, int elemento, int posicao)
{
    int lenVector = length_vector(v);
    if (posicao < lenVector)
    {
        v->vet[posicao] = elemento;
        return true;
    }
    else
    {
        free_vector(&v);
        v = (Vector *)calloc(2, lenVector);
        return false;
    }
}

bool replaceIn_vector(Vector *v, int posicao, int novoElemento)
{
    v->vet[posicao] = novoElemento;

    return true;    
}