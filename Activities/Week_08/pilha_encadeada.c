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

Pilha *pilha_criar()
{
    Pilha *new_stack = (Pilha *)malloc(sizeof(Pilha));
    new_stack->qtde = 0;
    new_stack->topo = NULL;
    return new_stack;
}

void pilha_destruir(Pilha **endereco)
{
}

bool pilha_empilhar(Pilha *stack, TipoElemento element)
{
    No *new_knot = (No *)malloc(sizeof(No));
    new_knot->dado = element;
    new_knot->anterior = NULL;

    new_knot->anterior = stack->topo;

    stack->topo = new_knot;
    stack->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{
}

bool pilha_vazia(Pilha *p)
{
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