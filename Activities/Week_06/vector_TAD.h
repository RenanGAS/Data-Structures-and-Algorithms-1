#ifndef _VECTOR_TAD_H_
#define _VECTOR_TAD_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct vector Vector;

Vector *create_vector();
bool addIn_vector(Vector *v, int elemento);
bool putIn_vector(Vector *v, int elemento, int posicao);
bool replaceIn_vector(Vector *v, int posicao, int novoElemento);
bool rmPosition_vector(Vector *v, int posicao, int *endereco);
int rmElement_vector(Vector *v, int elemento);
int lenght_vector(Vector *v);
bool elementIn_vector(Vector *v, int posicao, int *saida);
int positionIn_vector(Vector *v, int elemento);
void print_vector(Vector *v);
void free_vector(Vector **endVetor);
bool toString_vector(Vector *v, char *saida);

#endif