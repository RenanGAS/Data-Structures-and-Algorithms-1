#include "tad_produto.h"

void show_product(Produto *p)
{
    printf("\n=> ");
    printf("ID = #%d | ", produto_codigo(p));
    char desc_p[50];
    produto_descricao(p, desc_p);
    printf("Descricao = \"%s\" | ", desc_p);
    printf("Preco atual = RS %.2lf\n", produto_preco(p));
}

int main()
{
    printf("\nTESTE PRODUTO_CRIAR | PRODUTO_CODIGO | PRODUTO_DESCRICAO | PRODUTO_PRECO\n");
    char desc_p1[50] = "Teclado Gamer";
    Produto *new_p1 = produto_criar(1000, desc_p1, 32.5);
    printf("\nRESULTADO:\n");
    show_product(new_p1);

    printf("\nTESTE PRODUTO_ALTERA_PRECO\n");
    produto_altera_preco(new_p1, 30.9);
    produto_altera_preco(new_p1, 35.1);
    produto_altera_preco(new_p1, 50.5);
    produto_altera_preco(new_p1, 51.4);
    produto_altera_preco(new_p1, 60.3);
    printf("\nRESULTADO:\n");
    printf("\n=> NOVO PRECO = RS %.2lf\n", produto_preco(new_p1));

    printf("\nTESTE PRODUTO_MEDIA_PRECO\n");
    double av_p1 = produto_media_preco(new_p1);
    printf("\nRESULTADO: \n");
    printf("\n=> RS %.2lf\n", av_p1);

    printf("\nTESTE PRODUTO_DESTRUIR\n");
    produto_destruir(&new_p1);
    printf("\nRESULTADO:\n");
    if (new_p1 == NULL)
    {
        printf("\n=> PRODUTO DESTRUIDO COM SUCESSO\n");
    }
    else
    {
        printf("\n=> ERRO: NAO FOI POSSIVEL DESTRUIR O PRODUTO\n");
    }

    return 0;
}