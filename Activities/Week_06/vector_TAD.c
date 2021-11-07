#include "vector_TAD.h"
#include <stdlib.h>

struct vector
{
    int *vet;
    int tam;
    int qtd;
};

void double_vector(Vector *v, Vector **end_v)
{
    int tam_origin = v->tam;

    Vector *doubleVector = (Vector *)calloc(tam_origin * 2, sizeof(int));
    doubleVector->tam = tam_origin * 2;
    doubleVector->qtd = v->qtd;

    for (int i = 0; i < tam_origin; i++)
    {
        doubleVector->vet[i] = v->vet[i];
    }

    free(*end_v);
    *end_v = doubleVector;
}

bool validate_vector(Vector *v)
{
    int t = v->tam;
    int q = v->qtd;

    if (t == q)
    {
        double_vector(v, &v);
        return false;
    }
    else
    {
        return true;
    }
}

Vector *create_vector()
{
    Vector *newVector = (Vector *)calloc(10, sizeof(int));
    newVector->tam = 10;
    newVector->qtd = 0;

    return newVector;
}

bool addIn_vector(Vector *v, int elemento)
{
    if (validate_vector(v))
    {
        int q = v->qtd;
        v->vet[q] = elemento;
        return true;
    }
    else
    {
        return false;
    }
}

bool putIn_vector(Vector *v, int elemento, int posicao)
{
}

bool replaceIn_vector(Vector *v, int posicao, int novoElemento)
{
}

bool rmPosition_vector(Vector *v, int posicao, int *endereco)
{
}

int rmElement_vector(Vector *v, int elemento)
{
}

int lenght_vector(Vector *v)
{
}

bool elementIn_vector(Vector *v, int posicao, int *saida)
{
}

int positionIn_vector(Vector *v, int elemento)
{
}

void print_vector(Vector *v)
{
}

void free_vector(Vector **endVetor)
{
}

bool toString_vector(Vector *v, char *saida)
{
}