#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ex02.c"

void teste_B()
{
    printf("\n---------- TESTE B --------------\n");
    
    char str[500];

    Lista *l1 = lista_criar();
    lista_anexar(l1, "BBB");
    lista_anexar(l1, "DDD");
    lista_anexar(l1, "FFF");
    lista_anexar(l1, "HHH");
    lista_anexar(l1, "JJJ");
    lista_anexar(l1, "KKK");

    lista_toString(l1, str);
    printf("%s\n", str);

    Lista *l2 = lista_criar();
    lista_anexar(l2, "AAA");
    lista_anexar(l2, "CCC");
    lista_anexar(l2, "EEE");
    lista_anexar(l2, "GGG");
    lista_anexar(l2, "III");
    lista_anexar(l2, "LLL");
    lista_anexar(l2, "MMM");
    lista_anexar(l2, "NNN");

    lista_toString(l2, str);
    printf("%s\n", str);

    lista_intercala(l1, l2);

    lista_toString(l1, str);
    printf("%s\n", str);
    lista_toString(l2, str);
    printf("%s\n", str);

    lista_destruir(&l1);
    lista_destruir(&l2);
}

int main()
{
    teste_B();

    return 0;
}