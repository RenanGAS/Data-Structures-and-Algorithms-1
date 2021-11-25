#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdbool.h>

typedef int TipoElemento;
/**************************************
* DADOS
**************************************/
typedef struct pilha Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void pilha_destruir(Pilha** endereco);
bool pilha_empilhar(Pilha* p, TipoElemento elemento);
bool pilha_desempilhar(Pilha* p, TipoElemento* saida); 
bool pilha_topo(Pilha* p, TipoElemento* saida); 
bool pilha_vazia(Pilha* p);
void pilha_toString(Pilha* p, char* saida);

#endif