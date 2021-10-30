#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

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

void start_timer(Timer *ptr_timer)
{
    time(&(ptr_timer->begin));
}

void stop_timer(Timer *ptr_timer)
{
    time(&(ptr_timer->end));
}

float result_timer(Timer *ptr_timer)
{
    float result = ptr_timer->end - ptr_timer->begin;
    return result;
}

void reset_timer(Timer *ptr_timer)
{
    ptr_timer->begin = 0;
    ptr_timer->end = 0;
}

void free_timer(Timer **end_ptr_timer)
{
    free(*(end_ptr_timer));
    *end_ptr_timer = NULL;
}

/*-----------------------------------------
                Passo 2.1
Criar testes para os protótipos das funções
-------------------------------------------*/

int main()
{
    printf("\nTESTE INICIALIZADO:\n\n");

    printf("- Testando create_timer\n");
    Timer *timer = create_timer();
    assert(timer != NULL);

    printf("- Testando start_timer\n");
    start_timer(timer);
    assert(timer->begin != 0);

    long int end = 1000*1000*1000;
    for (int i = 0; i < end; i++)
    {
    }
    printf("- Testando stop_timer\n");
    stop_timer(timer);
    assert(timer->end != 0);
    assert(timer->end != timer->begin);

    printf("- Testando result_timer\n");
    float result = result_timer(timer);
    assert(result != 0);

    printf("- Testando reset_timer\n");
    reset_timer(timer);
    assert(timer->begin == 0);
    assert(timer->end == 0);

    printf("- Testando free_timer\n");
    Timer *ptr_test = timer;
    free_timer(&timer);
    assert(timer != ptr_test);

    printf("\nTESTE FINALIZADO!\n");
    
    return 0;
}
