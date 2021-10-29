#include <stdio.h>
#include <assert.h>

/*---------------------------- 
            Passo 1.3 
    Definição do nome do tipo
------------------------------*/

typedef struct
{

} Timer;

/*--------------------------------------- 
                Passo 1.4 
    Definição dos protótipos das funções
-----------------------------------------*/

Timer *create_timer();
void free_timer(Timer **end_ptr_timer);
void start_timer(Timer *ptr_timer);
void stop_timer(Timer *ptr_timer);
void reset_timer(Timer *ptr_timer);
char *result_timer(Timer *ptr_timer);

/*-----------------------------------------
                Passo 2.1
Criar testes para os protótipos das funções
-------------------------------------------*/

int main()
{
    Timer *t1 = timer_criar();

    /**
     * Medir o tempo de execução de um trecho de código que realiza
     * 1.000.000.000 de somas e divisões  
     */
    long int soma = 0;
    double divisao = 1;

    int interacoes = 1000 * 1000 * 1000;
    printf("Executando %d de operacoes\n", interacoes);

    timer_start(t1);
    //-----------------------------------------------
    for (int i = 0; i < interacoes; i++)
    {
        soma += i;
        divisao /= 2;
    }
    //-----------------------------------------------
    timer_stop(t1);
    printf("Tempo decorrido: %.2f\n\n", timer_resultado(t1));

    /**
     * Medir o tempo de percorrer uma matriz
     */
    long int linhas = 100000;
    long int colunas = 100000;
    printf("Executando %ld de operacoes\n", linhas * colunas);

    timer_reset(t1);
    timer_start(t1);
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
    timer_stop(t1);
    printf("Tempo decorrido: %.2f\n", timer_resultado(t1));

    timer_desalocar(&t1);
}
