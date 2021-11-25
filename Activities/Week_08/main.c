#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilha.h"

int main()
{

    Pilha *p1 = pilha_criar();
    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 30);

    char str[200];
    pilha_toString(p1, str);
    printf("%s\n", str); //[10,20,30]

    int elemento;

    pilha_topo(p1, &elemento);
    printf("Topo: %d\n", elemento); // 30

    while (!pilha_vazia(p1))
    { // 30 20 10
        pilha_desempilhar(p1, &elemento);
        printf("Desempilhado: %d\n", elemento);
    }

    /***********************************************
    * OPERAÇÕES NA PILHA VAZIA
    ************************************************/
    if (!pilha_desempilhar(p1, &elemento))
    {
        printf("Pilha vazia");
    }

    if (!pilha_topo(p1, &elemento))
    {
        printf("Pilha vazia");
    }

    pilha_toString(p1, str);
    printf("%s\n", str); //[]

    pilha_destruir(&p1);

    return 0;
}