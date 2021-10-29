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
    printf("- Testando create_timer\n");
    Timer *timer0 = create_timer();
    Timer *timer1 = create_timer();
    assert(timer0 != NULL);
    assert(timer1 != NULL);

    printf("- Testando start_timer\n");
    printf("- Testando stop_timer\n");
    for (int i = 0; i < 100; i++)
    {
        if (i == 10)
        {
            start_timer(timer0);
        }
        else if (i == 11)
        {
            start_timer(timer1);
        }
    }
    stop_timer(timer0);
    stop_timer(timer1);
    assert(timer0->milisec != 0);
    assert(timer1->milisec != 0);

    printf("- Testando result_timer\n");
    char *result0 = result_timer(timer0);
    char *result1 = result_timer(timer1);
    assert(result0[0] != 0);
    assert(result1[0] != 0);

    printf("- Testando reset_timer\n");
    reset_timer(timer0);
    reset_timer(timer1);
    assert(timer0->milisec == 0);
    assert(timer1->milisec == 0);

    printf("- Testando free_timer\n");
    free_timer(timer0);
    free_timer(timer1);
    assert(timer0 == NULL);
    assert(timer1 == NULL);

    printf("TESTE FINALIZADO\n");
    
    return 0;
}
