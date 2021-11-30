#include "pilha.h"

#define TAM 10

struct pilha
{
    int qtde;
    int tam;
    TipoElemento *vetor;
};

// Funções Auxiliares

void freeAtt_vector(TipoElemento **vector, TipoElemento *newVector)
{
    free(*vector);
    *vector = NULL;
    *vector = newVector;
}

void verifica_aumenta(Pilha *stack)
{
    if (stack->qtde == stack->tam)
    {
        int *new_vector = (int *)malloc(stack->tam * 2 * sizeof(TipoElemento));

        for (int i = 0; i < stack->qtde; i++)
        {
            new_vector[i] = stack->vetor[i];
        }

        freeAtt_vector(&stack->vetor, new_vector);

        printf("\nATUALIZACAO: VETOR DA PILHA DUPLICADO\n");
    }
}

void verifica_diminui(Pilha *stack)
{
    if (stack->qtde + 5 < stack->tam)
    {
        int *new_vector = (int *)malloc((stack->qtde + 5) * sizeof(TipoElemento));
        stack->tam = stack->qtde + 5;

        for (int i = 0; i < stack->qtde; i++)
        {
            new_vector[i] = stack->vetor[i];
        }

        freeAtt_vector(&stack->vetor, new_vector);

        printf("\nATUALIZACAO: VETOR DA PILHA DIMINUIDO. HA 5 ESPACOS VAZIOS\n");
        printf("\nqtde: %d\n\nTAM: %d\n", stack->qtde, stack->tam);
    }
}

// Funções Principais

Pilha *pilha_criar()
{
    Pilha *new_stack = (Pilha *)malloc(sizeof(Pilha));
    new_stack->vetor = (TipoElemento *)calloc(TAM, sizeof(TipoElemento));
    new_stack->tam = TAM;
    new_stack->qtde = 0;
    return new_stack;
}

bool pilha_empilhar(Pilha *stack, TipoElemento element)
{
    verifica_aumenta(stack);

    stack->vetor[stack->qtde] = element;
    stack->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha *stack, TipoElemento *output)
{
    if (stack->qtde > 0)
    {
        *output = stack->vetor[stack->qtde - 1];
        stack->qtde--;

        verifica_diminui(stack);
        
        return true;
    }

    return false;
}

bool pilha_topo(Pilha *stack, TipoElemento *top_element)
{
    if (stack->qtde > 0)
    {
        *top_element = stack->vetor[stack->qtde - 1];

        return true;
    }

    return false;
}

bool pilha_vazia(Pilha *stack)
{
    return (stack->qtde == 0 ? true : false);
}

void pilha_destruir(Pilha **stack_address)
{
    int old_value = (*stack_address)->vetor[1];

    free(&(*stack_address)->vetor[0]);

    if ((*stack_address)->vetor[1] == old_value)
    {
        printf("\nERRO: NAO FOI POSSIVEL EXCLUIR O VETOR DA PILHA\n");
    }

    free(*stack_address);
    *stack_address = NULL;

    printf("\nPILHA DESTRUIDA COM SUCESSO\n");
}

void pilha_toString(Pilha *stack, char *string)
{
    string[0] = '\0';
    strcat(string, "[");

    for (int i = stack->qtde - 1; i >= 0; i--)
    {
        char element[20];
        sprintf(element, "%d", stack->vetor[i]);
        strcat(string, element);

        if (i > 0)
        {
            strcat(string, ", ");
        }
    }

    strcat(string, "]");
}