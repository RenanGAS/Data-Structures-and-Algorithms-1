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

void fila_destruir(Fila **enderecoFila);

bool fila_inserir(Fila *f, TipoElemento elemento);
bool fila_remover(Fila *f, TipoElemento *saida);

bool fila_primeiro(Fila *f, TipoElemento *saida);

bool fila_vazia(Fila *f)
{
    if (!fila_ehValida(f))
        return true;

    return (f->qtde == 0 ? true : false);
}

int fila_tamanho(Fila *f)
{
    if (!fila_ehValida(f))
        return 0;

    return f->qtde;
}

void fila_toString(Fila *f, char *saida)
{
}