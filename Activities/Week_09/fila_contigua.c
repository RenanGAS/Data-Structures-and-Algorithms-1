#include "fila.h"
#include <string.h>

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct fila
{
    TipoElemento *vetor;
    int tam;
    int inicio;
    int fim;
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
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tam = TAM_INICIAL;
    f->qtde = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir(Fila **enderecoFila)
{
    if (enderecoFila == NULL)
        return;
    if (!fila_ehValida(*enderecoFila))
        return;

    Fila *f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
    if (f->qtde != f->tam)
    {
        f->vetor[f->fim] = elemento;
        f->fim++;
        f->qtde++;

        return true;
    }

    return false;
}

bool fila_remover(Fila *f, TipoElemento *saida)
{
    if (f->qtde != 0)
    {
        *saida = f->vetor[f->inicio];
        f->inicio++;
        f->fim++;
        f->qtde--;

        return true;
    }

    return false;
}

bool fila_primeiro(Fila *f, TipoElemento *saida)
{
    if (!fila_ehValida(f))
        return false;
    if (fila_vazia(f))
        return false;

    *saida = f->vetor[f->inicio];
    return true;
}

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

void fila_toString(Fila *f, char *str)
{
    str[0] = '\0';
    strcat(str, "[");

    for (int i = f->inicio; i < f->qtde; i++)
    {
        char aux[10];
        sprintf(aux, "%d", f->vetor[i]);
        strcat(str, aux);

        if (i + 1 != f->qtde)
        {
            strcat(str, ",");
        }
    }
    
    strcat(str, "]");
}
