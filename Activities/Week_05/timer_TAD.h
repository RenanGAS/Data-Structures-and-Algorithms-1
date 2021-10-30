#ifndef _TIMER_TAD_H_
#define _TIMER_TAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/*-----------------------------
            Passo 4.4 
        Encapsulando a TAD
-------------------------------*/

typedef struct timer Timer;

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

#endif
