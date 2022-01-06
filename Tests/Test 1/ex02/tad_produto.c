#include "tad_produto.h"

struct produto
{
    int codigo;
    char descricao[50];
    double ultimos_precos[4]; // armazena no máximo os últimos 4 preços praticados
    int qtd_precos;           // quantidade de preços armazenados no vetor ultimos_precos
};

Produto *produto_criar(int codigo, char *descricao, double preco)
{
    Produto *new_product = (Produto *)malloc(sizeof(Produto));
    new_product->codigo = codigo;
    new_product->ultimos_precos[0] = preco;
    new_product->qtd_precos = 1;
    strcpy(new_product->descricao, descricao);

    return new_product;
}

void produto_destruir(Produto **endProduto)
{
    free(*endProduto);
    *endProduto = NULL;
}

int produto_codigo(Produto *p)
{
    if (p->codigo == -1)
    {
        printf("\n\nERRO: CODIGO INVALIDO = %d\n\n", p->codigo);
        return -1;
    }
    else
    {
        return p->codigo;
    }
}

bool produto_descricao(Produto *p, char *saida)
{
    strcpy(saida, p->descricao);

    if (strcmp(saida, ""))
    {
        return true;
    }
    else
    {
        printf("\n\nERRO: DESCRICAO = \"%s\"\n\n", saida);
        return false;
    }
}

double produto_preco(Produto *p)
{
    if (p->ultimos_precos[p->qtd_precos - 1] == -1)
    {
        printf("\n\nERRO: PRECO = RS %.2lf\n\n", p->ultimos_precos[p->qtd_precos - 1]);
        return -1;
    }
    else
    {
        return p->ultimos_precos[p->qtd_precos - 1];
    }
}

double produto_media_preco(Produto *p)
{
    double sum = 0;

    for (int i = 0; i < p->qtd_precos; i++)
    {
        sum += p->ultimos_precos[i];
    }

    if (sum / p->qtd_precos == -1)
    {
        printf("\nERRO: MEDIA = %lf\n", sum / p->qtd_precos);
        return -1;
    }
    else
    {
        return sum / p->qtd_precos;
    }
}

bool produto_altera_preco(Produto *p, double preco)
{
    if (p->qtd_precos < 4)
    {
        p->ultimos_precos[p->qtd_precos] = preco;
        p->qtd_precos += 1;
    }
    else
    {
        for (int i = 1; i < 4; i++)
        {
            p->ultimos_precos[i - 1] = p->ultimos_precos[i];
        }

        p->ultimos_precos[3] = preco;
    }

    bool verify = false;

    for (int i = 0; i < 4; i++)
    {
        if (p->ultimos_precos[i] == preco)
        {
            verify = true;
        }
    }

    return verify;
}
