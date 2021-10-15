#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void dobrar(int *v, int tam)
{
    int i;
    int *doubleV = (int *)calloc(2 * tam, sizeof(int));
    for (i = 0; i < 2 * tam; i++)
    {
        if (i < tam)
        {
            doubleV[i] = v[i];
        }
        else
        {
            doubleV[i] = 0;
        }
    }

    free(v);
    v = doubleV;

    imprimirVetor(v, 12);
}

// exercício 06

typedef struct produto
{
    unsigned int codigo;
    char nome[50];
    float preco;
} Produto;

Produto *criaProduto(unsigned int cod, char nome[50], float preco)
{
    Produto *p = (Produto *)malloc(sizeof(Produto));
    p->codigo = cod;
    strcpy(p->nome, nome);
    p->preco = preco;

    return p;
}

void imprimeProduto(Produto *p)
{
    printf("\nCógido do produto: %d\n", p->codigo);
    printf("\nNome do produto: %s\n", p->nome);
    printf("\nPreço do produto: %f\n", p->preco);
}

// exercício 07

int main()
{
    int testV[6] = {1, 2, 3, 4, 5, 6};
    int *testV1 = (int *)calloc(6, sizeof(int));
    testV1[0] = 7;
    testV1[1] = 8;
    testV1[2] = 9;
    testV1[3] = 10;
    testV1[4] = 11;
    testV1[5] = 12;

    printf("\nTeste do exercício 1:\n");
    imprimirVetor(criarVetor(3, 1), 3);

    printf("\nTeste do exercício 2:\n");
    imprimirVetor(clonarVetor(testV, 6), 6);

    printf("\nTeste do exercício 3:\n");
    imprimirVetor(criarVetorAleatorio(5, 100), 5);

    printf("\nTeste do exercício 4:\n");
    incrementaVetor(testV, 6);
    imprimirVetor(testV, 6);

    printf("\nTeste do exercício 5:\n");
    imprimirVetor(testV1, 6);
    dobrar(testV1, 6);

    printf("\nTeste do exercício 6:\n");
    imprimeProduto(criaProduto(0, "Pão", 9.99));

    return 0;
}