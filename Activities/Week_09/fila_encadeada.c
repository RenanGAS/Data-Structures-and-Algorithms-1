#include "fila.h"
#include <string.h>

/**************************************
* DADOS
**************************************/
typedef struct no
{
    int dado;
    struct no *anterior;
} No;

struct fila
{
    No *inicio;
    No *fim;
    int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila *f)
{
    return (f != NULL ? true : false);
}

No *no_criar(TipoElemento dado)
{
    No *new_knot = (No *)malloc(sizeof(No));
    new_knot->dado = dado;
    new_knot->anterior = NULL;

    return new_knot;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila *fila_criar()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
    No *new_knot = no_criar(elemento);

    if (f->qtde == 0)
    {
        f->inicio = new_knot;
    }
    else
    {
        f->fim->anterior = new_knot;
    }

    f->fim = new_knot;
    f->qtde++;

    return true;
}

bool fila_remover(Fila *f, TipoElemento *saida)
{
}

bool fila_primeiro(Fila *f, TipoElemento *saida)
{
    *saida = f->inicio->dado;
    
    return (f->inicio != NULL ? true : false);
}

bool fila_vazia(Fila *f)
{
    if (!fila_ehValida(f))
        return true;

    return (f->qtde == 0 ? true : false);
}

void fila_destruir(Fila **enderecoFila)
{
}

int fila_tamanho(Fila *f)
{
    if (!fila_ehValida(f))
        return 0;

    return f->qtde;
}

void fila_toString(Fila *f, char *saida)
{
    saida[0] = '\0';

    strcat(saida, "[");

    No *aux = f->inicio;

    while (aux != NULL)
    {
        char dado[10];
        sprintf(dado, "%d", aux->dado);
        strcat(saida, dado);
        aux = aux->anterior;

        if (aux != NULL)
        {
            strcat(saida, ",");
        }
    }

    strcat(saida, "]");
}