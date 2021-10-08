#include <stdio.h>

typedef struct produto{
    int codigo;
    char descricao[12];
    float preco;
} Produto;

int main()
{
    // a)

    Produto prodA = {1, "Teclado", 98.50};
    Produto prodB = {2, "Mouse", 65.00};
    Produto prodC = {3, "Webcam", 130.00};

    Produto vet[4];
    vet[0] = prodA;
    vet[1] = prodB;
    vet[2].codigo = prodC.codigo;
    strcpy(vet[2].descricao, prodC.descricao);
    vet[2].preco = prodC.preco;

    return 0;
}