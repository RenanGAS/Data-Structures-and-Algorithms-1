#include <stdio.h>
#include <stdlib.h>
#include "vector_TAD.h"

int main()
{
	Vector *v = create_vector();

	printf("\nTESTE ADDIN_VECTOR\n");

	addIn_vector(v, 10);
	addIn_vector(v, 20);
	addIn_vector(v, 30);

	printf("\nRESULTADO:\n");
	print_vector(v); // [10, 20, 30, 0, 0, 0, 0, 0, 0, 0]

	printf("\nTESTE PUTIN_VECTOR\n");

	printf("\nPUTIN_1\n");
	putIn_vector(v, 15, 1);

	printf("\nRESULTADO_1:\n");
	print_vector(v); // [10, 15, 20, 30, 0, 0, 0, 0, 0, 0]

	printf("\nPUTIN_2\n");
	putIn_vector(v, 5, 0);

	printf("\nRESULTADO_2:\n");
	print_vector(v); // [5, 10, 15, 20, 30, 0, 0, 0, 0, 0]

	printf("\nTESTE REPLACEIN_VECTOR\n");

	replaceIn_vector(v, 5, 40);

	printf("\nRESULTADO:\n");
	print_vector(v); // [5, 10, 15, 20, 30, 40, 0, 0, 0, 0]

	printf("\nTESTE RMPOSITION_VECTOR\n");
	printf("\nRMPOSITION_1\n");
	int elemento;
	if (rmPosition_vector(v, 1, &elemento))
	{
		printf("\nRESULTADO_1:\n");
		printf("\nO elemento %d foi removido\n", elemento);
		print_vector(v);
	}

	printf("\nRMPOSITION_2\n");
	printf("\nRESULTADO_2:\n");
	if (!rmPosition_vector(v, 10, &elemento))
	{
		printf("Remocao invalida\n");
	}
	print_vector(v);

	printf("\nTESTE RMELEMENT_VECTOR\n");
	if (rmElement_vector(v, 20))
	{
		printf("\nRESULTADO:\n");
		print_vector(v);
	}

	printf("\nTESTE LENGTH_VECTOR:\n");
	int lenVector = length_vector(v);

	printf("\nRESULTADO: %d\n", lenVector);

	printf("\nTESTE ELEMENTIN_VECTOR\n");
	int elemento1 = 0;
	elementIn_vector(v, 3, &elemento1);

	printf("\nRESULTADO: %d\n", elemento1);

	printf("\nTESTE POSITIONIN_VECTOR\n");
	int pos = positionIn_vector(v, 30);

	printf("\nRESULTADO: %d\n", pos);

	printf("\nTESTE TOSTRING_VECTOR\n");
	char str[200];
	print_vector(v);
	toString_vector(v, str);
	printf("\nRESULTADO: ");
	printf("%s", str);
}