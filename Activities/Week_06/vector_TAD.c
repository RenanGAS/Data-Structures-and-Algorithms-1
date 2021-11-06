#include "vector_TAD.h"

struct timer
{
};

// Timer *create_timer()
// {
//     Timer *ptr_timer = (Timer *)calloc(2, sizeof(long int));
//     return ptr_timer;
// }

// void start_timer(Timer *ptr_timer)
// {
//     time(&(ptr_timer->time_begin));
// }

// void stop_timer(Timer *ptr_timer)
// {
//     time(&(ptr_timer->time_end));
// }

// double result_timer(Timer *ptr_timer)
// {
//     if (ptr_timer->time_end == 0)
//     {
//         return -1;
//     }
    
//     double result = (double)(ptr_timer->time_end - ptr_timer->time_begin);
//     return result;
// }

// void reset_timer(Timer *ptr_timer)
// {
//     ptr_timer->time_begin = 0;
//     ptr_timer->time_end = 0;
// }

// void free_timer(Timer **end_ptr_timer)
// {
//     free(*(end_ptr_timer));
//     *end_ptr_timer = NULL;
// }