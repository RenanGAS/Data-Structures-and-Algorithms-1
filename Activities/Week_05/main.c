#include <stdio.h>
#include <assert.h>

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

// Passo 1.3 - Definição do nome da TAD

typedef struct
{

} Timer;

// Passo 1.4 - Construir protótipos para as funções

Timer *create_timer();
void free_timer(Timer **end_ptr_timer);
void start_timer(Timer *ptr_timer);
void stop_timer(Timer *ptr_timer);
void reset_timer(Timer *ptr_timer);
float result_timer(Timer *ptr_timer);

// Passo 2.1 - Criar testes para as funções

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
