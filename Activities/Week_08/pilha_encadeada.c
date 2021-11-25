#include "pilha.h"
#include<stdlib.h>

/**************************************
* Especificação do dados
**************************************/
typedef struct no{
    TipoElemento dado;
    struct no* prox;
}No;

struct pilha{
    int qtde;
    No* topo;
};

/**************************************
* Implementação das funções
**************************************/
Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->qtde = 0;
    p->topo = NULL;
    return p;
}
void pilha_destruir(Pilha** endereco);
bool pilha_empilhar(Pilha* p, TipoElemento elemento){

    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;

    novo->prox = p->topo;
    
    p->topo = novo;
    p->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida); 
bool pilha_topo(Pilha* p, TipoElemento* saida); 
bool pilha_vazia(Pilha* p);
void pilha_toString(Pilha* p, char* saida);