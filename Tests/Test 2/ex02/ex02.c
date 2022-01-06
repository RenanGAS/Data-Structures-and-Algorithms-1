#include "lista_encadeada.c"

void insereEsquerda(No *referencia, No *novo)
{
    novo->ant = referencia->ant;
    novo->prox = referencia;
    referencia->ant->prox = novo;
    referencia->ant = novo;
}

No *extraiPrimeiroNo(Lista *l)
{
    if (l->inicio == NULL)
        return NULL;

    No *aux = l->inicio;
    l->inicio = l->inicio->prox;
    if (l->inicio != NULL)
    {
        l->inicio->ant = NULL;
    }
    aux->prox = NULL;
    l->qtde--;
    return aux;
}

void lista_concatena(Lista *a, Lista *b)
{
    a->fim->prox = b->inicio;
    b->inicio->ant = a->fim;
    a->fim = b->fim;
    a->qtde = a->qtde + b->qtde;
    b->qtde = 0;
    b->inicio = b->fim = NULL;
}

void lista_intercala(Lista *a, Lista *b)
{
    // Se a lista A e a lista B estiverem vazias OU somente a lista B estiver vazia não há o que fazer

    if (lista_vazia(a) && lista_vazia(b))
        return;
    if (lista_vazia(b))
        return;

    if (lista_vazia(a)) // Se a lista A está vazia, apenas movemos os elementos da lista B para ela
    {
        a->inicio = b->inicio;
        a->fim = b->fim;
        a->qtde = a->qtde + b->qtde;
        b->inicio = b->fim = NULL;
        b->qtde = 0;
    }
    else
    { // Ambas as lista possuem elementos

        if (strcmp(b->inicio->dado, a->inicio->dado) <= 0)
        { // Se o primeiro elemento de B for menor do que o primeiro de A

            No *temp = extraiPrimeiroNo(b); // Extrai o primeiro nó da lista B

            // Encadeia esse nó na primeira posição da lista A

            temp->prox = a->inicio;
            a->inicio->ant = temp;
            a->inicio = temp;

            // Incrementa quantidade da lista A

            a->qtde++;
        }
        else   // Se a lista A tem apenas um elemento, e este é menor que o primeiro elemento de B, concatenamos a Lista A e B.
        {      // A condição é necessária para evitar erro em auxA. Realizando a função concatena, o código não entra no laço de repetição.

            if (a->qtde == 1)
            {
                lista_concatena(a, b);
            }
        }

        No *auxA = a->inicio->prox; // posiciona o auxA no segundo nó de A

        while (b->inicio != NULL)
        { // enquanto houver nós no B

            if (strcmp(b->inicio->dado, auxA->dado) <= 0)
            { // Se o auxB for menor que auxA

                // Extrai o primeiro nó de B

                No *temp = extraiPrimeiroNo(b);

                // insere esse nó a esquerda de auxA

                insereEsquerda(auxA, temp);
            }
            else
            {
                // andar com o auxA

                auxA = auxA->prox;

                // se chegou no final da lista A, transferir o restante dos elementos da lista B

                if (auxA == NULL)
                {
                    lista_concatena(a, b);
                }
            }
        }
    }
}
