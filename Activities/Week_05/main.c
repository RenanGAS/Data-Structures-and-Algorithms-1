#include <stdio.h>

#include "timer_TAD.h"

// Passo 4.4 - Encapsular a struct

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
