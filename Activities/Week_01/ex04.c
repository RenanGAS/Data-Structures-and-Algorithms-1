#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char equation[50];
    double a, e, b, c;
    double r1, r2;

    FILE *valuesIn = fopen("files/values.in", "r");
    fscanf(valuesIn, "%s", equation);
    fclose(valuesIn);

    for (int i = 0; i < strlen(equation); i++)
    {
        if (i == 0)
        {
            a = equation[i] - 48;
        }
        else if (i == 3)
        {
            e = equation[i] - 48;
        }
        else if (i == 5)
        {
            b = equation[i] - 48;
        }
        else if (i == 8)
        {
            c = equation[i] - 48;
        }
    }

    r1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
    r2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);

    printf("\n=> Raízes:\n");
    printf("\n\t=> r1 = %.2lf\n\t=> r2 = %.2lf\n\n", r1, r2);

    return 0;
}