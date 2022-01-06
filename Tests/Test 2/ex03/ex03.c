#include "lista_encadeada.c"
#include <string.h>

char **lista_vetor(Lista *l, int *endTamanho)
{
    if (l == NULL)
    {
        *endTamanho = 0;
        return NULL;
    }

    *endTamanho = l->qtde;
    char **vetor_strings = (char **)calloc(*endTamanho, sizeof(char *));
    No *aux = l->inicio;

    for (int i = 0; i < *endTamanho; i++)
    {
        char *vetor_elemento = (char *)malloc(strlen(aux->dado) + 1);

        vetor_elemento[0] = '\0';
        strcat(vetor_elemento, aux->dado);
        vetor_strings[i] = vetor_elemento;

        aux = aux->prox;
    }

    return vetor_strings;
}
