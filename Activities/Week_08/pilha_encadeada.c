#include "pilha.h"
#include <stdlib.h>

typedef struct no
{
    TipoElemento dado;
    struct no *anterior;
} No;

struct pilha
{
    int qtde;
    No *topo;
};

// Funções Auxiliares

No *no_criar(TipoElemento element)
{
    No *new_knot = (No *)malloc(sizeof(No));
    new_knot->dado = element;
    new_knot->anterior = NULL;

    return new_knot;
}


// Funções Principais

Pilha *pilha_criar()
{
    Pilha *new_stack = (Pilha *)malloc(sizeof(Pilha));
    new_stack->qtde = 0;
    new_stack->topo = NULL;
    return new_stack;
}

bool pilha_empilhar(Pilha *stack, TipoElemento element)
{
    No *new_knot = no_criar(element);

    new_knot->anterior = stack->topo;

    stack->topo = new_knot;
    stack->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha *stack, TipoElemento *removed_element)
{
    if (stack->qtde > 0)
    {
        No *aux = stack->topo;
        *removed_element = aux->dado;
        stack->topo = aux->anterior;

        free(aux);
        
        stack->qtde--;

        return true;
    }

    return false;
}

bool pilha_topo(Pilha *stack, TipoElemento *top_element)
{
    if (stack->qtde > 0)
    {
        *top_element = stack->topo->dado;

        return true;
    }

    return false;
}

bool pilha_vazia(Pilha *stack)
{
    if (stack->qtde > 0)
    {
        return false;
    }

    return true;
}

void pilha_destruir(Pilha **stack_address)
{
    free(*stack_address);
    *stack_address = NULL;

    printf("\nPILHA DESTRUIDA COM SUCESSO\n");
}

void pilha_toString(Pilha *stack, char *string)
{
    No *aux = stack->topo;

    strcat(string, "[");

    for (int i = stack->qtde; i >= 1; i--)
    {
        char element[20];
        sprintf(element, "%d", aux->dado);
        strcat(string, element);

        if (i > 1)
        {
            strcat(string, ", ");
        }

        aux = aux->anterior;
    }

    strcat(string, "]");
}