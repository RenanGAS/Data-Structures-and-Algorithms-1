#include<stdio.h>
#include<stdlib.h>
#include "vector_TAD.h"

int main(){
	Vector* v = create_vector();

	putIn_vector(v, 10, 0);
	putIn_vector(v, 20, 1);
	putIn_vector(v, 30, 2);
	print_vector(v); // [10,20,30]
	
	putIn_vector(v, 15, 1);
	print_vector(v); // [10,15,20,30]
	
	putIn_vector(v, 5, 0);
	print_vector(v); // [5,10,15,20,30]
	
	int elemento;
	if (rmPosition_vector(v, 1, &elemento)){
	    printf("O elemento %d foi removido\n", elemento); // O elemento 10 foi removido
	    print_vector(v); // [5,15,20,30]
	}
	
	// if (vet_removerPosicao(v, 10, &elemento) == false){
	if (!rmPosition_vector(v, 10, &elemento)){
	    printf("Remocao invalida\n");
	} 
	
	char str[200];
	toString_vector(v, str);
	printf("%s", str); //[5,15,20,30]
}