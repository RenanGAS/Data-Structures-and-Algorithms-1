/*-----------------------
        Passo 1.1
    Abstração dos dados

- Minutos
- Segundos
- Milisegundos
--------------------------*/

/*----------------------------------
            Passo 1.2 
        Abstração da operações 

Operação 1: Criar o timer
Operação 2: Desalocar o timer
Operação 3: Iniciar o timer
Operação 4: Para o timer
Operação 5: Limpar/Resetar o timer
Operação 6: Obter o tempo gasto
-------------------------------------*/

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
