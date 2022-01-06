#include "lista_encadeada.c"

void lista_concatena(Lista *a, Lista *b)
{
    if (a->qtde != 0 && b->qtde != 0)
    {
        a->fim->prox = b->inicio;
        b->inicio->ant = a->fim;
        a->fim = b->fim;
    }
    else if (a->qtde == 0)
    {
        a->inicio = b->inicio;
        a->fim = b->fim;
    }

    a->qtde = a->qtde + b->qtde;
    b->qtde = 0;
    b->inicio = b->fim = NULL;
}
