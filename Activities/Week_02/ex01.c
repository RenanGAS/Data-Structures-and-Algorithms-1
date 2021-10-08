#include <stdio.h>

int main()
{
    int v[4] = {1, 2, 3, 4};
    int i = 30;
    int *p = v;
    int *w = v + 2;
    int *x = &i;

    printf("\nEndereços do vetor v:\n");
    printf("\n%p  %p  %p  %p\n", &v[0], &v[1], &v[2], &v[3]);
    printf("\nEndereço de i: %p\n", &i);

    printf("\nValor de p: %p\n", p);
    printf("\nValor de w: %p\n", w);
    printf("\nValor de x: %p\n", x);

    printf("\n-------------------------\n");

    printf("\np = %p\n", p);
    printf("\nv = %p\n", v);
    printf("\n&v[0] = %p\n", &v[0]);
    printf("\nv + 1 = %p\n", v + 1);

    printf("\n-------------------------\n");

    printf("\n*(v+2) = %d\n", *(v + 2));
    printf("\nw = %p\n", w);
    printf("\n*w = %d\n", *w);
    printf("\nw[1] = %d\n", w[1]);

    printf("\n-------------------------\n");

    printf("\nx = %p\n", x);
    printf("\n&x = %p\n", &x);
    printf("\n*x = %d\n", *x);
    printf("\nx[0] = %d\n", x[0]);

    printf("\n-------------------------\n");

    printf("\np + 3 = %p\n", p + 3);
    printf("\n&p[3] = %p\n", &p[3]);
    printf("\n*(p+3) = %d\n", *(p + 3));
    printf("\np[3] = %d\n", p[3]);

    printf("\n-------------------------\n");

    printf("\nv[0] = %d\n", *(p));
    printf("\nv[1] = %d\n", *(p + 1));
    printf("\nv[2] = %d\n", *(p + 2));
    printf("\nv[3] = %d\n\n", *(p + 3));

    return 0;
}