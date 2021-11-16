#include <stdio.h>
#include <stdlib.h>

typedef struct vectorElement
{
    int value;
    struct vectorElement *endNext;
} VectorElement;

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

int main()
{
    VectorElement *e;
    vectorChain(&e);
    printVectorChain(e);
}