#include "pilha.h"

#define TAM 10

struct pilha
{
    int qtde;
    int tam;
    TipoElemento *vetor;
};

// Funções Auxiliares

void freeAtt_vector(TipoElemento **vector, TipoElemento *newVector)
{
    free(*vector);
    *vector = NULL;
    *vector = newVector;
}

void verifica_aumenta(Pilha *stack)
{
    if (stack->qtde == stack->tam)
    {
        int *new_vector = (int *)malloc(stack->tam * 2 * sizeof(TipoElemento));

        for (int i = 0; i < stack->qtde; i++)
        {
            new_vector[i] = stack->vetor[i];
        }

        freeAtt_vector(&stack->vetor, new_vector);

        printf("\nATUALIZACAO: VETOR DA PILHA DUPLICADO\n");
    }
}

void verifica_diminui(Pilha *p);

// Funções Principais

Pilha *pilha_criar()
{
    Pilha *new_stack = (Pilha *)malloc(sizeof(Pilha));
    new_stack->vetor = (TipoElemento *)calloc(TAM, sizeof(TipoElemento));
    new_stack->tam = TAM;
    new_stack->qtde = 0;
    return new_stack;
}

bool pilha_empilhar(Pilha *stack, TipoElemento element)
{
    verifica_aumenta(stack);

    stack->vetor[stack->qtde] = element;
    stack->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida);
bool pilha_topo(Pilha *p, TipoElemento *saida);
void pilha_destruir(Pilha **endereco);
bool pilha_vazia(Pilha *p);

void pilha_toString(Pilha *stack, char *string)
{
    strcat(string, "[");

    for (int i = 0; i < stack->qtde; i++)
    {
        char element[20];
        sprintf(element, "%d", stack->vetor[i]);
        strcat(string, element);

        if (i < stack->qtde - 1)
        {
            strcat(string, ", ");
        }
    }

    strcat(string, "]");
}