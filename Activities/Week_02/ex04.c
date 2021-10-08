#include <stdio.h>

int main()
{
    int m[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int *p = (int*)m;
    int *w = (int*)m + 6;

    printf("\nElementos e endereços da matriz m:\n");
    printf("\n%d (%p)  %d (%p)  %d (%p)  %d (%p)  %d (%p)  %d (%p)  %d (%p)  %d (%p)\n", m[0][0], &m[0][0], m[0][1], &m[0][1], m[1][0], &m[1][0], m[1][1], &m[1][1], m[2][0], &m[2][0], m[2][1], &m[2][1], m[3][0], &m[3][0], m[3][1], &m[3][1]);
    printf("\nValor de w: %p\n", w);
    printf("\nValor de p: %p\n", p);

    printf("\n-------------------------\n");

    printf("\nm = %p\n", m);
    printf("\nm[0] = %p\n", m[0]);
    printf("\np = %p\n", p);
    printf("\nm+1 = %p\n", m+1);
    printf("\nm[1] = %p\n", m[1]);

    printf("\n-------------------------\n");

    printf("\np+3 = %p\n", p+3);
    printf("\nm[0][0] = %d\n", m[0][0]);
    printf("\n*m[0] = %d\n", *m[0]);
    printf("\n*p = %d\n", *p);
    printf("\np[0] = %d\n", p[0]);

    printf("\n-------------------------\n");

    printf("\nm[3][1] = %d\n", m[3][1]);
    printf("\n*(m[3]+1) = %d\n", *(m[3]+1));
    printf("\n*(p+(3*2)+1) = %d\n", *(p+(3*2)+1));
    printf("\nw[1] = %d\n", w[1]);
    printf("\n*(w+1) = %d\n", *(w+1));

    printf("\n-------------------------\n");

    int num_linhas = 4, num_colunas = 2;

    for (int i = 0; i < num_linhas; i++)
    {
        for (int j = 0; j < num_colunas; j++)
        {
            if (j == 0)
            {
                printf("\n");
            }
            // printf("(%p) %d  ", &m[i][j], m[i][j]);  // Trecho 1
            printf("(%p) %d  ", (p + (i*num_colunas) + j), *(p + (i*num_colunas) + j)); // # Trecho 2
        }
    }

    printf("\n\n");

    return 0;
}
