#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Compilar o código deste jeito: gcc ex04.c -o ex04.exe -lm
    
    char binStr[50] = "";
    int sum, e = 0;

    FILE *binConverterIn = fopen("files/binConverter.in", "r");
    fscanf(binConverterIn, "%s", binStr);
    fclose(binConverterIn);

    for (int i = strlen(binStr) - 1; i >= 0; i--)
    {
        if (binStr[i] == '1')
        {
            sum += pow(2, e);
        }
        e++;
    }

    FILE *binConverterOut = fopen("files/binConverter.out", "w");
    fprintf(binConverterOut, "\n=> Binário: %s\n\n=> Decimal: %d", binStr, sum);
    fclose(binConverterOut);

    return 0;
}