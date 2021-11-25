#include "pilha.h"


#define TAM 10

/**************************************
* Especificação do dados
**************************************/
struct pilha{
    int qtde;
    int tam;
    TipoElemento* vetor;
};

/**************************************
* Funções auxiliares
**************************************/
void verifica_aumenta(Pilha* p);
void verifica_diminui(Pilha* p);

/**************************************
* Implementação das funções
**************************************/
Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->vetor = (TipoElemento*)calloc(TAM, sizeof(TipoElemento));
    p->tam = TAM;
    p->qtde = 0;
    return p;
}

void pilha_destruir(Pilha** endereco);

bool pilha_empilhar(Pilha* p, TipoElemento elemento){
    verifica_aumenta(p);

    p->vetor[p->qtde] = elemento;
    p->qtde++;
    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida); 
bool pilha_topo(Pilha* p, TipoElemento* saida); 
bool pilha_vazia(Pilha* p);
void pilha_toString(Pilha* p, char* saida);