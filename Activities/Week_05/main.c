#include <stdio.h>
#include <assert.h>
#include "timer_TAD.h"

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