#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilha.h"

int main()
{
    printf("\nTESTE PILHA_CRIAR || PILHA_EMPILHAR || PILHA_TOSTRING\n");
    Pilha *new_stack1 = pilha_criar();
    pilha_empilhar(new_stack1, 65);
    pilha_empilhar(new_stack1, 66);
    pilha_empilhar(new_stack1, 67);
    pilha_empilhar(new_stack1, 68);
    pilha_empilhar(new_stack1, 69);
    pilha_empilhar(new_stack1, 70);
    pilha_empilhar(new_stack1, 71);
    pilha_empilhar(new_stack1, 72);
    pilha_empilhar(new_stack1, 73);
    pilha_empilhar(new_stack1, 74);

    char str1[200] = "";
    pilha_toString(new_stack1, str1);
    printf("\nRESULTADO:\n");
    printf("\n%s\n", str1);

    printf("\nTESTE PILHA_DESEMPILHAR || PILHA_TOPO\n");
    int removed_element = 0;
    pilha_desempilhar(new_stack1, &removed_element);
    printf("\nRESULTADO:\n");
    printf("\nELEMENTO REMOVIDO: %d\n", removed_element);
    int top_element = 0;
    pilha_topo(new_stack1, &top_element);
    printf("\nELEMENTO NO TOPO: %d\n", top_element);
    char str2[200];
    pilha_toString(new_stack1, str2);
    printf("\n%s\n", str2);

    printf("\nTESTE PILHA_VAZIA\n");
    printf("\nRESULTADO:\n");
    while (!pilha_vazia(new_stack1))
    {
        pilha_desempilhar(new_stack1, &removed_element);
        printf("\nELEMENTO DESEMPILHADO: %d\n", removed_element);
    }
    if (pilha_vazia(new_stack1))
    {
        printf("\nPILHA ESVAZIADA COM SUCESSO\n");
    }

    if (!pilha_desempilhar(new_stack1, &removed_element))
    {
        printf("\nERRO AO DESEMPILHAR: A PILHA ESTA VAZIA\n");
    }

    if (!pilha_topo(new_stack1, &top_element))
    {
        printf("\nERRO AO ACESSAR O TOPO: A PILHA ESTA VAZIA\n");
    }

    pilha_destruir(&new_stack1);

    return 0;
}