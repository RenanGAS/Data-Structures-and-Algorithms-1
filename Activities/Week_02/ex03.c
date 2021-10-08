#include <stdio.h>

int main()
{
    int v1[3] = {1, 2, 3};
    int v2[3] = {4, 5, 6};
    int *p1 = v1;
    int *p2 = v2;
    int *m[2] = {v1, v2};
    int **pm = m;

    printf("\nEndereços dos elementos de v1:\n");
    printf("\n%p  %p  %p\n", &v1[0], &v1[1], &v1[2]);
    printf("\nEndereços dos elementos de v2:\n");
    printf("\n%p  %p  %p\n", &v2[0], &v2[1], &v2[2]);
    printf("\nValor de p1: %p\n", p1);
    printf("\nValor de p2: %p\n", p2);
    printf("\nElementos de m:\n");
    printf("\n%p  %p\n", m[0], m[1]);
    printf("\nEndereços dos elementos de m:\n");
    printf("\n%p  %p\n", &m[0], &m[1]);
    printf("\nValor de pm: %p\n", pm);

    printf("\n-------------------------\n");

    printf("\np1 = %p\n", p1);
    printf("\nv1 = %p\n", v1);
    printf("\np1+2 = %p\n", p1 + 2);
    printf("\nv1+2 = %p\n", v1 + 2);
    printf("\np2[1] = %d\n", p2[1]);

    printf("\n-------------------------\n");

    printf("\n*(v2+1) = %d\n", *(v2 + 1));
    printf("\nm = %p\n", m);
    printf("\n*m = %p\n", *m);
    printf("\npm = %p\n", pm);
    printf("\n*pm = %p\n", *pm);

    printf("\n-------------------------\n");

    printf("\nm[0] = %p\n", m[0]);
    printf("\n*(m+1) = %p\n", *(m + 1));
    printf("\n*pm[1] = %d\n", *pm[1]);
    printf("\n**(m+1) = %d\n", **(m + 1));
    printf("\nm[0][2] = %d\n", m[0][2]);

    printf("\n-------------------------\n");

    printf("\npm = %p\n", pm);
    printf("\npm+1 = %p\n", pm + 1);
    printf("\n*(pm+1) = %p\n", *(pm + 1));
    printf("\n*(pm+1)+2 = %p\n", *(pm + 1) + 2);
    printf("\n*(*(pm+1)+2) = %d\n\n", *(*(pm + 1) + 2));

    printf("\n-------------------------\n");

    printf("\nv1[0] = %d\n", *(pm[0]));
    printf("\nv1[1] = %d\n", pm[0][1]);
    printf("\nv1[2] = %d\n", pm[0][2]);
    printf("\nv2[0] = %d\n", *(pm[1]));
    printf("\nv2[1] = %d\n", pm[1][1]);
    printf("\nv2[2] = %d\n\n", pm[1][2]);

    return 0;
}