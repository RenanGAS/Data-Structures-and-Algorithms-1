#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*--------------------------------------------
                    Passo 3.1
    Escolher forma de representação dos dados
                    na memória
----------------------------------------------*/

typedef struct timer
{
    long int begin;
    long int end;
} Timer;

/*--------------------------------------- 
            Passo 1.4 & Passo 3.2
    Definição dos protótipos das funções
   & Revisar a forma de alocação dos dados
-----------------------------------------*/

Timer *create_timer(); // Alocará 16 bytes dinamicamente para o Timer
void free_timer(Timer **end_ptr_timer);
void start_timer(Timer *ptr_timer);
void stop_timer(Timer *ptr_timer);
void reset_timer(Timer *ptr_timer);
float result_timer(Timer *ptr_timer);

/*---------------------------
          Passo 3.3
    Implementar as funções
-----------------------------*/

Timer *create_timer()
{
    Timer *ptr_timer = (Timer *)calloc(2, sizeof(long int));
    return ptr_timer;
}

/*-----------------------------------------
                Passo 2.1
Criar testes para os protótipos das funções
-------------------------------------------*/

int main()
{
    Timer *t1 = create_timer();

    /**
     * Medir o tempo de execução de um trecho de código que realiza
     * 1.000.000.000 de somas e divisões  
     */
    long int soma = 0;
    double divisao = 1;

    int interacoes = 1000 * 1000 * 1000;
    printf("Executando %d de operacoes\n", interacoes);

    start_timer(t1);
    //-----------------------------------------------
    for (int i = 0; i < interacoes; i++)
    {
        soma += i;
        divisao /= 2;
    }
    //-----------------------------------------------
    stop_timer(t1);
    printf("Tempo decorrido: %.2f\n\n", result_timer(t1));

    /**
     * Medir o tempo de percorrer uma matriz
     */
    long int linhas = 100000;
    long int colunas = 100000;
    printf("Executando %ld de operacoes\n", linhas * colunas);

    reset_timer(t1);
    start_timer(t1);
    //-----------------------------------------------
    long int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            // leitura da matriz
        }
    }

    //-----------------------------------------------
    stop_timer(t1);
    printf("Tempo decorrido: %.2f\n", result_timer(t1));

    free_timer(&t1);
}
