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

    char str[200];
    pilha_toString(new_stack1, str);
    printf("\nRESULTADO:\n");
    printf("\n%s\n", str);

    // int element;

    // pilha_topo(new_stack1, &element);
    // printf("Topo: %d\n", element); 

    // while (!pilha_vazia(new_stack1))
    // {
    //     pilha_desempilhar(new_stack1, &element);
    //     printf("Desempilhado: %d\n", element);
    // }

    // /***********************************************
    // * OPERAÇÕES NA PILHA VAZIA
    // ************************************************/
    // if (!pilha_desempilhar(new_stack1, &element))
    // {
    //     printf("Pilha vazia");
    // }

    // if (!pilha_topo(new_stack1, &element))
    // {
    //     printf("Pilha vazia");
    // }

    // pilha_toString(new_stack1, str);
    // printf("%s\n", str); //[]

    // pilha_destruir(&new_stack1);

    return 0;
}