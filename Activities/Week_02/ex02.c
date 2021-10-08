#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int *v[4] = {&a, &b, &c, &d};
    int **p = v;

    printf("\nValor dos endereços de a, b, c, d:\n");
    printf("\n%p  %p  %p  %p\n", &a, &b, &c, &d);
    printf("\nElementos do vetor v:\n");
    printf("\n%p  %p  %p  %p\n", v[0], v[1], v[2], v[3]);
    printf("\nEndereços do vetor v:\n");
    printf("\n%p  %p  %p  %p\n", &v[0], &v[1], &v[2], &v[3]);
    printf("\nValor de &v[0]: %p\n", &v[0]);
    printf("\nValor de p: %p\n", p);

    printf("\n-------------------------\n");

    printf("\np = %p\n", p);
    printf("\n*p = %p\n", *p);
    printf("\n**p = %d\n", **p);
    printf("\np[1] = %p\n", p[1]);
    printf("\n*p[1] = %d\n", *p[1]);

    printf("\n-------------------------\n");

    printf("\n**(p+2) = %d\n", **(p + 2));
    printf("\nv = %p\n", v);
    printf("\nv[3] = %p\n", v[3]);
    printf("\nv+3 = %p\n", v + 3);
    printf("\n*(v+3) = %p\n", *(v + 3));
    printf("\n**(v+3) = %d\n", **(v + 3));

    printf("\n-------------------------\n");

    printf("\na = %d\n", **v);
    printf("\nb = %d\n", **(v + 1));
    printf("\nc = %d\n", **(v + 2));
    printf("\nd = %d\n\n", **(v + 3));
    return 0;
}