#include <stdio.h>
#include <stdlib.h>
#include "vector_TAD.h"

void teste_concatena()
{
	printf("\nTESTE VET_CONCATENA\n");

	Vector *teste_v1 = create_vector();
	addIn_vector(teste_v1, 10);
	addIn_vector(teste_v1, 20);
	addIn_vector(teste_v1, 30);
	print_vector(teste_v1);

	Vector *teste_v2 = create_vector();
	addIn_vector(teste_v2, 40);
	addIn_vector(teste_v2, 50);
	print_vector(teste_v2);

	printf("\nRESULTADO:\n");
	Vector *teste_v3 = vet_concatena(teste_v1, teste_v2);
	print_vector(teste_v3);
}

void teste_intercala()
{
	printf("\nTESTE VET_INTERCALA\n");

	Vector *teste_v1 = create_vector();
	addIn_vector(teste_v1, 1);
	addIn_vector(teste_v1, 2);
	addIn_vector(teste_v1, 4);
	addIn_vector(teste_v1, 5);
	print_vector(teste_v1);

	Vector *teste_v2 = create_vector();
	addIn_vector(teste_v2, 3);
	addIn_vector(teste_v2, 6);
	addIn_vector(teste_v2, 7);
	addIn_vector(teste_v2, 8);
	addIn_vector(teste_v2, 9);
	addIn_vector(teste_v2, 10);
	print_vector(teste_v2);

	printf("\nRESULTADO:\n");
	Vector *teste_v3 = vet_intercala(teste_v1, teste_v2);
	print_vector(teste_v3);
}

int main()
{
	teste_concatena();
	teste_intercala();

	return 0;
}