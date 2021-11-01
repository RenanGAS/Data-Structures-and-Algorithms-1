#include "timer_TAD.h"
#include <time.h>

// Passo 4.4 - Encapsular a struct

struct timer
{
    long int time_begin;
    long int time_end;
};


// Passo 3.3 - Implementar as funções

Timer *create_timer()
{
    Timer *ptr_timer = (Timer *)calloc(2, sizeof(long int));
    return ptr_timer;
}

void start_timer(Timer *ptr_timer)
{
    ptr_timer->time_begin = clock();
}

void stop_timer(Timer *ptr_timer)
{
    ptr_timer->time_end = clock();
}

double result_timer(Timer *ptr_timer)
{
    double result = (double)(ptr_timer->time_end - ptr_timer->time_begin)/CLOCKS_PER_SEC;
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