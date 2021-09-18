#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct palavra{
	int ordem;
	char letra;
	char texto[255];
};

int main(){

	struct palavra primeiraPalavra;

	primeiraPalavra.ordem = 10;

	printf("Ordem: %d", primeiraPalavra.ordem);

	return 0;
}