#include <stdio.h>

int main()
{
    int m[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int *p = (int*)m;
    int *w = (int*)(m + 6);

    int num_linhas = 4, num_colunas = 2;

    for (int i = 0; i < num_linhas; i++)
    {
        for (int j = 0; j < num_colunas; j++)
        {
            if (j == 0)
            {
                printf("\n");
            }
            // printf("%d (%p)  ", m[i][j], &m[i][j]);  # Trecho 1
            printf("%d (%p)  ", *(p + (i*num_colunas) + j), (p + (i*num_colunas) + j)); // # Trecho 2
        }
    }

    printf("\n\n");

    return 0;
}
