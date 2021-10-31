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
