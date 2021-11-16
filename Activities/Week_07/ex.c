#include <stdio.h>
#include <stdlib.h>

typedef struct vectorElement
{
    int value;
    struct vectorElement *endNext;
} VectorElement;

typedef struct treeElement
{
    int value;
    struct treeElement *endPrevious;
    struct treeElement *endNext;
} TreeElement;

void vectorChain(VectorElement **e)
{
    VectorElement *element = (VectorElement *)malloc(sizeof(VectorElement));
    element->value = 1;
    element->endNext = NULL;
    *e = element;

    element = (VectorElement *)malloc(sizeof(VectorElement));
    element->value = 2;
    element->endNext = NULL;
    (*e)->endNext = element;

    element = (VectorElement *)malloc(sizeof(VectorElement));
    element->value = 3;
    element->endNext = NULL;
    (*e)->endNext->endNext = element;
}

void printVectorChain(VectorElement *e)
{
    printf("\nElementos do vetor encadeado:\n");

    VectorElement *aux = e;

    while (aux != NULL)
    {
        printf("\n%d\n", aux->value);
        aux = aux->endNext;
    }
}

void treeChain(TreeElement **a)
{
    TreeElement *element = (TreeElement *)malloc(sizeof(TreeElement));
    element->value = 50;
    element->endPrevious = NULL;
    element->endNext = NULL;
    *a = element;

    element = (TreeElement *)malloc(sizeof(TreeElement));
    element->value = 30;
    element->endPrevious = NULL;
    element->endNext = NULL;

    (*a)->endPrevious = element;

    element = (TreeElement *)malloc(sizeof(TreeElement));
    element->value = 60;
    element->endPrevious = NULL;
    element->endNext = NULL;

    (*a)->endNext = element;

    element = (TreeElement *)malloc(sizeof(TreeElement));
    element->value = 20;
    element->endPrevious = NULL;
    element->endNext = NULL;

    (*a)->endPrevious->endPrevious = element;

    element = (TreeElement *)malloc(sizeof(TreeElement));
    element->value = 40;
    element->endPrevious = NULL;
    element->endNext = NULL;

    (*a)->endPrevious->endNext = element;
}

void printTreeChain(TreeElement *a)
{
    printf("\nElementos da árvore encadeada:\n");

    printf("\n%d\n", a->value);
    printf("\n%d\n", a->endPrevious->value);
    printf("\n%d\n", a->endNext->value);
    printf("\n%d\n", a->endPrevious->endPrevious->value);
    printf("\n%d\n", a->endPrevious->endNext->value);
}

int main()
{
    VectorElement *e;
    vectorChain(&e);
    printVectorChain(e);

    TreeElement *a;
    treeChain(&a);
    printTreeChain(a);
}