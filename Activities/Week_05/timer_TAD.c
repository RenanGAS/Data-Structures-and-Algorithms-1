#include "timer_TAD.h"

/*---------------------
        Passo 4.4
    Encapsulando a TAD
-----------------------*/

struct timer
{
    long int begin;
    long int end;
};

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