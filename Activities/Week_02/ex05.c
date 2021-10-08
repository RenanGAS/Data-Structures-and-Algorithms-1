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
    Produto prod = {10, "Teclado", 98.50};
    Produto *p = (Produto *)&prod;
    Produto *pi = (Produto *)&prod;
    Produto *pc = (Produto *)&prod.descricao;
    Produto *pf = (Produto *)&prod.preco;

    printf("\nElementos e endereços do objeto prod:\n");
    printf("\n%d (%p)  %s (%p)  %f (%p)\n", prod.codigo, &prod.codigo, prod.descricao, &prod.descricao, prod.preco, &prod.preco);
    printf("\nValor de p: %p\n", p);
    printf("\nValor de pi: %p\n", pi);
    printf("\nValor de pc: %p\n", pc);
    printf("\nValor de pf: %p\n", pf);

    printf("\n-------------------------\n");

    printf("\np = %p\n", p);
    printf("\n&p = %p\n", &p);
    printf("\n&prod = %p\n", &prod);
    printf("\nprod.codigo = %d\n", prod.codigo);
    printf("\n&prod.codigo = %p\n", &prod.codigo);

    printf("\n-------------------------\n");

    printf("\np->codigo = %d\n", p->codigo);
    printf("\n&p->codigo = %p\n", &p->codigo);
    printf("\nprod.descricao = %s\n", prod.descricao);
    printf("\n&prod.descricao = %p\n", &prod.descricao);
    printf("\np->descricao = %s\n", p->descricao);

    printf("\n-------------------------\n");

    printf("\n&p->descricao = %p\n", &p->descricao);
    printf("\nprod.preco = %f\n", prod.preco);
    printf("\n&prod.preco = %p\n", &prod.preco);
    printf("\np->preco = %f\n", p->preco);
    printf("\n&p->preco = %p\n", &p->preco);

    printf("\n-------------------------\n");

    printf("\nValor do código:\n");
    prod.codigo = 11;
    printf("\n%d\n", prod.codigo);
    (*p).codigo = 12;
    printf("\n%d\n", prod.codigo);
    p->codigo = 13;
    printf("\n%d\n", prod.codigo);
    (*pi).codigo = 14;
    printf("\n%d\n", prod.codigo);
    pi->codigo = 15;
    printf("\n%d\n", prod.codigo);

    printf("\n-------------------------\n");

    printf("\nValor da descrição:\n");
    strcpy(prod.descricao, "Teclado G");
    printf("\n%s\n", prod.descricao);
    strcpy((*pc).descricao, "Teclado Ma");
    printf("\n%s\n", (*pc).descricao);
    strcpy(pc->descricao, "Teclado S");
    printf("\n%s\n", pc->descricao);

    printf("\nValor do produto:\n");
    prod.preco = 200.99;
    printf("\n%f\n", prod.preco);
    (*pf).preco = 234.99;
    printf("\n%f\n", (*pf).preco);
    pf->preco = 220.99;
    printf("\n%f\n\n", pf->preco);

    return 0;
}