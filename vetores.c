#include<stdio.h>
#include<stdlib.h>

void main(){
	int vetor[3], cont;

	vetor[0] = 5;
	vetor[1] = 10;
	vetor[2] = 15;

	printf("\nPosicao 0: %d", vetor[0] );
	printf("\nPosicao 0: %d", vetor[1] );
	printf("\nPosicao 0: %d", vetor[2] );

	for(cont=0; cont<3 ; cont++){
		printf("\nPosicao %d : %d", cont, vetor[cont]);
	}
}