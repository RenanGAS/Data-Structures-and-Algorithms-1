#include "vector_TAD.h"
#include <stdlib.h>

struct vector
{
    int *vet;
    int tam;
    int qtd;
};


// Funções Adicionadas

Vector *createWithSize_vector(int n)
{
    Vector *newVector = (Vector *)calloc(n, sizeof(int));
    newVector->tam = n;
    newVector->qtd = 0;

    return newVector;
}

void freeAndAttribute_vector(Vector **endVetor, Vector *newVector)
{
    free(*endVetor);
    *endVetor = NULL;
    *endVetor = newVector;
}

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

    freeAndAttribute_vector(end_v, doubleVector);
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


// Funções Principais

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
        v->qtd += 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool putIn_vector(Vector *v, int elemento, int posicao)
{
    if (v->qtd < v->tam)
    {
        Vector *newV = createWithSize_vector(v->tam + 1);

        int countForV = 0;

        for (int i = 0; i < newV->tam; i++)
        {
            if (i != posicao)
            {
                newV->vet[i] = v->vet[countForV];
                countForV += 1;
            }
            else
            {
                newV->vet[i] = elemento;
            }
        }

        freeAndAttribute_vector(&v, newV);

        return true;
    }
    else
    {
        double_vector(v, &v);
        return false;
    }
}

bool replaceIn_vector(Vector *v, int posicao, int novoElemento)
{
    v->vet[posicao] = novoElemento;
    return true;
}

bool rmPosition_vector(Vector *v, int posicao, int *endereco)
{
    Vector *newV = createWithSize_vector(v->tam - 1);

    int countForV = 0;

    for (int i = 0; i < newV->tam; i++)
    {
        if (countForV != posicao)
        {
            newV->vet[i] = v->vet[countForV];
        }

        countForV++;
    }

    endereco = v->vet[posicao];

    freeAndAttribute_vector(&v, newV);

    return true;
}

int rmElement_vector(Vector *v, int elemento)
{
    Vector *newV = createWithSize_vector(v->tam - 1);

    int stop = 0;
    int countForV = 0;

    for (int i = 0; i < newV->tam; i++)
    {
        if ((v->vet[countForV] == elemento) && stop == 0)
        {
            newV->vet[i] = v->vet[countForV];
            stop = 1;
        }
        else
        {
            newV->vet[i] = v->vet[countForV];
        }
        countForV++;
    }

    freeAndAttribute_vector(&v, newV);

    return true;
}

int length_vector(Vector *v)
{
    return v->qtd;
}

bool elementIn_vector(Vector *v, int posicao, int *saida)
{
    if ((posicao >= 0) && (posicao < v->tam))
    {
        for (int i = 0; i < v->vet; i++)
        {
            if (v->vet[i] == v->vet[posicao])
            {
                saida = v->vet[i];
                break;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

int positionIn_vector(Vector *v, int elemento)
{
    int stop = 0;
    int *pos = -1;

    for (int i = 0; i < v->tam; i++)
    {
        if (v->vet[i] == elemento)
        {
            pos = &(v->vet[i]);
            break;
        }
    }

    return pos;
}

void print_vector(Vector *v)
{
    printf("\n[");
    for (int i = 0; i < v->tam; i++)
    {
        if (i == (v->tam - 1))
        {
            printf("%d]\n", v->vet[i]);
        }
        else
        {
            printf("%d, ", v->vet[i]);
        }
    }
}

void free_vector(Vector **endVetor)
{
    free(*endVetor);
    *endVetor = NULL;
}

bool toString_vector(Vector *v, char *saida)
{
    saida[0] = "[";
    for (int i = 1; i <= v->tam; i++)
    {
        itoa(v->vet[i - 1], &(saida[i]), 10);
    }
    saida[v->tam + 1] = "]";

    return true;
}