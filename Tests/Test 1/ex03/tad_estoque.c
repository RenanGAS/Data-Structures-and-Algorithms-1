#include "tad_estoque.h"

#define TAM 100

struct estoque
{
    char descricao[50];
    Produto *vetor[TAM];
    int qtde;
};

Estoque *estoque_criar(char *descricao)
{
    Estoque *new_stock = (Estoque *)malloc(sizeof(Estoque));
    strcpy(new_stock->descricao, descricao);
    new_stock->qtde = 0;

    return new_stock;
}

void estoque_destruir(Estoque **endEstoque)
{
    int qtd_p = (*endEstoque)->qtde;

    for (int i = 0; i < qtd_p; i++)
    {
        Produto **pi = &(*endEstoque)->vetor[i];
        produto_destruir(pi);
    }
    
    free(*endEstoque);
    *endEstoque = NULL;
}

bool estoque_anexar(Estoque *e, Produto *p)
{
    if (e->qtde < TAM)
    {
        e->vetor[e->qtde] = p;
        e->qtde += 1;
        return true;
    }
    else
    {
        printf("\n=> ERRO: QUANTIDADE MAXIMA DE PRODUTOS ATINGIDA\n");
        return false;
    }
}

int estoque_remover_elemento(Estoque *e, char *descricao)
{
    int pos_toRemove = -1;

    for (int i = 0; i < e->qtde; i++)
    {
        char desc_pi[50] = "";
        produto_descricao(e->vetor[i], desc_pi);

        if (strcmp(desc_pi, descricao) == 0)
        {
            produto_destruir(&(e->vetor[i]));
            e->vetor[i] = NULL;
            
            pos_toRemove = i;
        }
    }

    if (pos_toRemove == -1)
    {
        printf("\nERRO: DESCRICAO \"%s\" DESCONHECIDA\n", descricao);
        return -1;
    }

    for (int i = pos_toRemove + 1; i < e->qtde; i++)
    {
        e->vetor[i - 1] = e->vetor[i];
    }

    e->qtde -= 1;

    return pos_toRemove;
}

void estoque_imprimir(Estoque *e)
{
    printf("\n=> %s:\n", e->descricao);
    printf("\n  [");
    for (int i = 0; i < e->qtde; i++)
    {
        char desc_pi[50] = "";
        produto_descricao(e->vetor[i], desc_pi);

        if (i != e->qtde - 1)
        {
            printf("(%d, %s, %.2lf), ", produto_codigo(e->vetor[i]), desc_pi, produto_preco(e->vetor[i]));
        }
        else
        {
            printf("(%d, %s, %.2lf)", produto_codigo(e->vetor[i]), desc_pi, produto_preco(e->vetor[i]));
        }
    }
    printf("]\n");
}