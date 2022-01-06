#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ex01.c"


void teste_A()
{
    printf("\n---------- TESTE A --------------\n");
    
    Lista *l1 = lista_criar();
    lista_anexar(l1, "AAA");
    lista_anexar(l1, "BBB");
    lista_anexar(l1, "CCC");
    lista_anexar(l1, "DDD");

    Lista *l2 = lista_criar();
    lista_anexar(l2, "EEE");
    lista_anexar(l2, "FFF");
    lista_anexar(l2, "GGG");

    char str[500];
    lista_toString(l1, str);
    printf("%s\n", str); 
    lista_toString(l2, str);
    printf("%s\n", str); 

    lista_concatena(l1, l2);
    lista_toString(l1, str);
    printf("%s\n", str);
    lista_toString(l2, str);
    printf("%s\n", str); 

    lista_destruir(&l1);
    lista_destruir(&l2);
}

int main()
{
    teste_A();

    return 0;
}