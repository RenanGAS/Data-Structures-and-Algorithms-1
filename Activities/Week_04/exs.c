#include <stdio.h>
#include <stdlib.h>

void printVector(int *v, int tam)
{
    printf("\n[");
    for (int i = 0; i < tam; i++)
    {
        if (i == tam - 1)
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
    }
    printf("]\n");
}

// Exercício 1

int sumElem1(int *v, int tam)
{
    int sum = 0;

    for (int i = 0; i < tam; i++)
    {
        sum += v[i];
    }

    return sum;
}

void sumElem2(int *v, int tam, int *s)
{
    int sum = 0;

    for (int i = 0; i < tam; i++)
    {
        sum += v[i];
    }

    *s = sum;
}

// Exercício 2

int highestElem1(int *v, int tam)
{
    int hElem = v[0];

    for (int i = 1; i < tam; i++)
    {
        if (hElem < v[i])
        {
            hElem = v[i];
        }
    }

    return hElem;
}

void highestElem2(int *v, int tam, int *hElem)
{
    for (int i = 1; i < tam; i++)
    {
        if (*hElem < v[i])
        {
            *hElem = v[i];
        }
    }
}

// Exercício 3

int *mergeVectors1(int *v1, int tam1, int *v2, int tam2)
{
    int tam3 = tam1 + tam2;
    int *mergedV = (int *)calloc(tam3, sizeof(int));

    int pos_v1 = 0;
    int pos_v2 = 0;

    for (int i = 0; i < tam3; i++)
    {
        if ((pos_v1 < tam1 && (v1[pos_v1] < v2[pos_v2])) || pos_v2 >= tam2)
        {
            mergedV[i] = v1[pos_v1];
            pos_v1++;
        }
        else
        {
            mergedV[i] = v2[pos_v2];
            pos_v2++;
        }
    }

    return mergedV;
}

void mergeVectors2(int *v1, int tam1, int *v2, int tam2, int *mergedV, int tamMerged)
{
    int pos_v1 = 0;
    int pos_v2 = 0;

    for (int i = 0; i < tamMerged; i++)
    {
        if ((pos_v1 < tam1 && (v1[pos_v1] < v2[pos_v2])) || pos_v2 >= tam2)
        {
            mergedV[i] = v1[pos_v1];
            pos_v1++;
        }
        else
        {
            mergedV[i] = v2[pos_v2];
            pos_v2++;
        }
    }
}

// Exercício 4    // Não testado

// int numberOfChar1(char str[])
// {
//     int count = 0;

//     for (int i = 0; str[i] != "\0"; i++)
//     {
//         if (str[i] != 32)
//         {
//             count++;
//         }
//     }

//     return count;
// }

// void numberOfChar2(char str[], int *count)
// {
//     for (int i = 0; str[i] != "\0"; i++)
//     {
//         if (str[i] != 32)
//         {
//             *count++;
//         }
//     }
// }

// // Exercício 5  // Não testado

// char *reverseStr1(char str[], int tam)
// {
//     char *inversedStr = (char *)calloc(tam, sizeof(char));

//     for (int i = tam - 1; i >= 0; i--)
//     {
//         inversedStr[i] = str[i];
//     }

//     return inversedStr;
// }

// void reverseStr2(char str[], int tam, char *inversedStr)
// {
//     for (int i = tam - 1; i >= 0; i--)
//     {
//         inversedStr[i] = str[i];
//     }
// }

int main()
{
    int vet[5] = {1, 2, 3, 4, 5};

    printf("\nTestes do exercício 1:\n");
    int sum1 = sumElem1(vet, 5);
    printf("\n=> Usando return: %d\n", sum1);
    int sum2 = 0;
    sumElem2(vet, 5, &sum2);
    printf("\n=> Usando a estratégia do scanf: %d\n\n", sum2);

    printf("\nTestes do exercício 2:\n");
    int hElem1 = highestElem1(vet, 5);
    printf("\n=> Usando return: %d\n", hElem1);
    int hElem2 = 0;
    highestElem2(vet, 5, &hElem2);
    printf("\n=> Usando a estratégia do scanf: %d\n", hElem2);

    printf("\nTeste do exercício 3:\n");
    int vet1[8] = {1, 3, 5, 7, 9, 11, 13, 14};
    printVector(vet1, 8);
    int vet2[6] = {2, 4, 6, 8, 10, 12};
    printVector(vet2, 6);
    printf("\n=> Usando return:\n");
    int *pVet1 = mergeVectors1(vet1, 8, vet2, 6);
    printVector(pVet1, 14);
    printf("\n=> Usando a estratégia do scanf:\n");
    int pVet2[14] = {};
    mergeVectors2(vet1, 8, vet2, 6, pVet2, 14); // Não testado
    printVector(pVet2, 14);

    // printf("\nTeste do exercício 4:\n"); // Não testado
    // char str[50] = " Me chamo Renan Guensuke Aoki Sakashita";
    // int numChar1 = numberOfChar1(str);
    // printf("\nUsando return: %d\n", numChar1);
    // int numChar2 = 0;
    // numberOfChar2(str, &numChar2);
    // printf("\nUsando a estratégia do scanf: %d\n", numChar2);

    // printf("\nTeste do exercício 5:\n"); // Não testado
    // char str[10] = "UTFPR - Campo Mourao";
    // // Dúvida na aplicação do return em strings
    // char reverseStr[10] = "";
    // reverseStr2(str, 10, reverseStr);
    // printf("\n=> Usando a estratégia do scanf: %s\n", reverseStr);

    return 0;
}