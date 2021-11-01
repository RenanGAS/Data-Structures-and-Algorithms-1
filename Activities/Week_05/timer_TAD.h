// Passo 4.5 - Incluir um "Guard" (guardião) em {nome}_TAD.h

#ifndef _TIMER_TAD_H_
#define _TIMER_TAD_H_

#include <stdio.h>
#include <stdlib.h>

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

// Passo 4.4 - Encapsular a struct

typedef struct timer Timer;

// Passo 3.2 - Revisar a forma de alocação de dados das funções

Timer *create_timer();
void free_timer(Timer **end_ptr_timer);
void start_timer(Timer *ptr_timer);
void stop_timer(Timer *ptr_timer);
void reset_timer(Timer *ptr_timer);
double result_timer(Timer *ptr_timer);

#endif