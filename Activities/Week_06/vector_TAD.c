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

// Funções Adicionadas

void freeAndAtt_intV_vector(Vector *v, int *newIntVector, int newTam)
{
    free(v->vet);
    v->vet = NULL;
    v->tam = newTam;
    v->vet = newIntVector;
}

void double_vector(Vector *v)
{
    int tam_origin = v->tam;

    int *doubleV = (int *)calloc(tam_origin * 2, sizeof(int));

    for (int i = 0; i < tam_origin; i++)
    {
        doubleV[i] = v->vet[i];
    }

    freeAndAtt_intV_vector(v, doubleV, tam_origin * 2);
}

bool validate_vector(Vector *v)
{
    int t = v->tam;
    int q = v->qtd;

    if (t == q)
    {
        double_vector(v);
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
    Vector *newVector = (Vector *)calloc(4, sizeof(int));
    int *int_vector = (int *)calloc(10, sizeof(int));
    newVector->vet = int_vector;
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
        int new_tam = v->tam + 1;
        int *new_intV = (int *)calloc(new_tam, sizeof(int));

        int countForV = 0;

        for (int i = 0; i < new_tam; i++)
        {
            if (i != posicao)
            {
                new_intV[i] = v->vet[countForV];
                countForV += 1;
            }
            else
            {
                new_intV[i] = elemento;
            }
        }

        freeAndAtt_intV_vector(v, new_intV, new_tam);

        v->qtd += 1;

        return true;
    }
    else
    {
        double_vector(v);
        return false;
    }
}

bool replaceIn_vector(Vector *v, int posicao, int novoElemento)
{
    v->vet[posicao] = novoElemento;

    if (posicao >= v->qtd)
    {
        v->qtd += 1;
    }
    return true;
}

bool rmPosition_vector(Vector *v, int posicao, int *endereco)
{
    int new_tam = v->tam - 1;
    int *new_intV = (int *)calloc(new_tam, sizeof(int));

    int countForV = 0;

    for (int i = 0; i < new_tam; i++)
    {
        if (countForV != posicao)
        {
            new_intV[i] = v->vet[countForV];
            countForV++;
        }
        else
        {
            countForV++;
            new_intV[i] = v->vet[countForV];
            countForV++;
        }
    }

    *endereco = v->vet[posicao];

    if (posicao < v->qtd)
    {
        v->qtd -= 1;
    }

    freeAndAtt_intV_vector(v, new_intV, new_tam);

    return true;
}

int rmElement_vector(Vector *v, int elemento)
{
    int new_tam = v->tam - 1;
    int *new_intV = (int *)calloc(new_tam, sizeof(int));

    int stop = 0;
    int countForV = 0;

    for (int i = 0; i < new_tam; i++)
    {
        if ((v->vet[countForV] == elemento) && stop == 0)
        {
            countForV++;
            new_intV[i] = v->vet[countForV];
            stop = 1;
            countForV++;
        }
        else
        {
            new_intV[i] = v->vet[countForV];
            countForV++;
        }
    }

    freeAndAtt_intV_vector(v, new_intV, new_tam);

    v->qtd -= 1;

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
        for (int i = 0; i < v->tam; i++)
        {
            if (v->vet[i] == v->vet[posicao])
            {
                *saida = v->vet[i];
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
    int pos = -1;

    for (int i = 0; i < v->tam; i++)
    {
        if (v->vet[i] == elemento)
        {
            pos = i;
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
    saida[0] = '[';
    for (int i = 1; i <= v->tam; i++)
    {
        snprintf((saida + i), sizeof(saida), "%d", v->vet[i]);
    }
    saida[v->tam + 1] = ']';

    return true;
}