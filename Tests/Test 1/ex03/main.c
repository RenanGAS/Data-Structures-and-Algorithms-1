#include "tad_estoque.h"
#include "tad_produto.h"

bool compare_integers(int a, int b)
{
    bool verify = false;

    if (a > b || a < b)
    {
        verify = true;
    }

    return verify;
}

int main()
{
    printf("\nTESTE ESTOQUE_CRIAR || ESTOQUE_ANEXAR || ESTOQUE IMPRIMIR\n");
    Estoque *new_e1 = estoque_criar("Estoque de Produtos Gamer");
    Produto *new_p1 = produto_criar(1000, "Teclado da Razer", 630.1);
    Produto *new_p2 = produto_criar(1001, "Mouse da Razer", 355.2);
    Produto *new_p3 = produto_criar(1002, "Headset da Razer", 1050.5);
    estoque_anexar(new_e1, new_p1);
    estoque_anexar(new_e1, new_p2);
    estoque_anexar(new_e1, new_p3);
    printf("\nRESULTADO:\n");
    estoque_imprimir(new_e1);

    printf("\nTESTE ESTOQUE_REMOVER_ELEMENTO\n");
    int index_removed = estoque_remover_elemento(new_e1, "Mouse da Razer");
    if (index_removed != -1)
    {
        printf("\nRESULTADO:\n");
        printf("\n=> PRODUTO [%d] REMOVIDO\n", index_removed);
    }
    estoque_imprimir(new_e1);

    printf("\nTESTE ESTOQUE_DESTRUIR\n");
    int code_p1 = produto_codigo(new_p1);
    int code_p3 = produto_codigo(new_p3);
    estoque_destruir(&new_e1);
    printf("\nRESULTADO:\n");

    if ((new_e1 == NULL) && compare_integers(produto_codigo(new_p1), code_p1) && compare_integers(produto_codigo(new_p3), code_p3))
    {
        printf("\n=> ESTOQUE DESTRUIDO COM SUCESSO\n");
    }
    else
    {
        printf("\n=> NAO FOI POSSIVEL DESTRUIR O ESTOQUE\n");
    }

    return 0;
}