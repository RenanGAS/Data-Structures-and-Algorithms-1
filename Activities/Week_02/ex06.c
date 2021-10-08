#include <stdio.h>
#include <string.h>

typedef struct produto
{
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

    printf("\na)\n\n");

    // Produto vet[4];
    // vet[0] = prodA;
    // vet[1] = prodB;
    // vet[2].codigo = prodC.codigo;
    // strcpy(vet[2].descricao, prodC.descricao);
    // vet[2].preco = prodC.preco;

    // printf("\nElementos e endereços do prodA:\n");
    // printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodA.codigo, &prodA.codigo, prodA.descricao, &prodA.descricao, prodA.preco, &prodA.preco);
    // printf("\nElementos e endereços do prodB:\n");
    // printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodB.codigo, &prodB.codigo, prodB.descricao, &prodB.descricao, prodB.preco, &prodB.preco);
    // printf("\nElementos e endereços do prodC:\n");
    // printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodC.codigo, &prodC.codigo, prodC.descricao, &prodC.descricao, prodC.preco, &prodC.preco);
    // printf("\nElementos do vetor vet:\n");
    // printf("\nvet[0] = {%d, %s, %.2f}  vet[1] = {%d, %s, %.2f}  vet[2] = {%d, %s, %.2f}  vet[3] = vazio\n", vet[0].codigo, vet[0].descricao, vet[0].preco, vet[1].codigo, vet[1].descricao, vet[1].preco, vet[2].codigo, vet[2].descricao, vet[2].preco);

    printf("\n-------------------------\n");

    printf("\nb)\n\n");

    Produto *vet[4];
    vet[0] = &prodA;
    vet[1] = &prodB;
    vet[2] = &prodC;

    printf("\nElementos e endereços do prodA:\n");
    printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodA.codigo, &prodA.codigo, prodA.descricao, &prodA.descricao, prodA.preco, &prodA.preco);
    printf("\nElementos e endereços do prodB:\n");
    printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodB.codigo, &prodB.codigo, prodB.descricao, &prodB.descricao, prodB.preco, &prodB.preco);
    printf("\nElementos e endereços do prodC:\n");
    printf("\n%d (%p)  %s (%p)  %f (%p)\n", prodC.codigo, &prodC.codigo, prodC.descricao, &prodC.descricao, prodC.preco, &prodC.preco);
    printf("\nElementos do vetor vet:\n");
    printf("\n(%p)  (%p)  (%p)  vazio\n", vet[0], vet[1], vet[2]);

    (*vet[2]).codigo = 100;
    printf("\n\nprodC.codigo = %d\n", prodC.codigo);
    strcpy(vet[1]->descricao, "Mouse gamer");
    printf("\nprodB.descricao = %s\n", prodB.descricao);
    Produto prodD = {4, "Headphone", 500.99};
    vet[3] = &prodD;
    printf("\nElementos e endereços do prodD:\n");
    printf("\n%d (%p)  %s (%p)  %f (%p)\n\n", prodD.codigo, &prodD.codigo, prodD.descricao, &prodD.descricao, prodD.preco, &prodD.preco);

    return 0;
}