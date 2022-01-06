#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ex03.c"

void teste_C()
{
    printf("\n---------- TESTE C --------------\n");
    
    Lista *l1 = lista_criar();
    lista_anexar(l1, "AAAAAAAAAAAAA");
    lista_anexar(l1, "BBBBBBBBBBBB");
    lista_anexar(l1, "CCCCCCCCCCC");
    lista_anexar(l1, "DDDDDDDDDD");
    lista_anexar(l1, "EEEEEEEEE");
    lista_anexar(l1, "FFFFFFFF");
    lista_anexar(l1, "GGGGGGG");
    lista_anexar(l1, "HHHHHH");
    lista_anexar(l1, "IIIII");
    lista_anexar(l1, "JJJJ");
    lista_anexar(l1, "KKK");
    lista_anexar(l1, "LL");
    lista_anexar(l1, "M");

    int tamanho = 0;
    char **vetor = lista_vetor(l1, &tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%s ", vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < tamanho; i++)
    {
        free(vetor[i]);
    }
    free(vetor);
}

int main()
{
    teste_C();

    return 0;
}