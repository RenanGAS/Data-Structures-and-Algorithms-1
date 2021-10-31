#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// Passo 1.1 - Abstração dos dados
/*
- Tempo Inicial;
- Tempo Final.
*/

// Passo 1.2 - Abstração das operações
/*
- Operação 1: Criar o Timer
- Operação 2: Marcar o tempo inicial
- Operação 3: Marcar o tempo final
- Operação 4: Calcular o resultado
- Operação 5: Resetar o Timer
- Operação 6: Desalocar o Timer
*/

// Passo 3.1 - Definir como será representado os dados da TAD

typedef struct timer
{
    long int time_begin;
    long int time_end;
} Timer;

// Passo 3.2 - Revisar a forma de alocação de dados das funções

Timer *create_timer();
void free_timer(Timer **end_ptr_timer);
void start_timer(Timer *ptr_timer);
void stop_timer(Timer *ptr_timer);
void reset_timer(Timer *ptr_timer);
float result_timer(Timer *ptr_timer);

// Passo 3.3 - Implementar as funções

Timer *create_timer()
{
    Timer *ptr_timer = (Timer *)calloc(2, sizeof(long int));
    return ptr_timer;
}

void start_timer(Timer *ptr_timer)
{
    time(&(ptr_timer->time_begin));
}

void stop_timer(Timer *ptr_timer)
{
    time(&(ptr_timer->time_end));
}

float result_timer(Timer *ptr_timer)
{
    float result = ptr_timer->time_end - ptr_timer->time_begin;
    return result;
}

void reset_timer(Timer *ptr_timer)
{
    ptr_timer->time_begin = 0;
    ptr_timer->time_end = 0;
}

void free_timer(Timer **end_ptr_timer)
{
    free(*(end_ptr_timer));
    *end_ptr_timer = NULL;
}

// Passo 2.1 - Criar testes para as funções

int main()
{
    printf("\nTESTE INICIALIZADO:\n\n");

    printf("- Testando create_timer\n");
    Timer *timer = create_timer();
    assert(timer != NULL);

    printf("- Testando start_timer\n");
    start_timer(timer);
    assert(timer->time_begin != 0);

    long int end = 1000*1000*1000;
    for (int i = 0; i < end; i++)
    {
    }

    printf("- Testando stop_timer\n");
    stop_timer(timer);
    assert(timer->time_end != 0);
    assert(timer->time_end != timer->time_begin);

    printf("- Testando result_timer\n");
    float result = result_timer(timer);
    assert(result != 0);

    printf("- Testando reset_timer\n");
    reset_timer(timer);
    assert(timer->time_begin == 0);
    assert(timer->time_end == 0);

    printf("- Testando free_timer\n");
    Timer *ptr_test = timer;
    free_timer(&timer);
    assert(timer != ptr_test);

    printf("\nTESTE FINALIZADO!\n");
    
    return 0;
}
