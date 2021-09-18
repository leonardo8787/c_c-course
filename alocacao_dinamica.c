#include<stdio.h>
#include<stdlib.h>

int* alocaVetor(int tamanho){
    
	//ponteiro auxiliar
	int *aux;

	//alocação dinâmica de Memória
	aux = (int *) malloc( tamanho * sizeof(int) );

	//retorna para o ponteiro que aponta pra primeira posição de memória de valor alocado;
	return aux;
}



int main(){
	
	int *vetor, tamanho, cont;

	printf("Digite um tamanho para o vetor: ");
	scanf("%d", &tamanho );

	//recebe o endereço de memória que foi alocado
	vetor = alocaVetor(tamanho);

    vetor[0]=0;
    vetor[1]=10;
    vetor[2]=20;
    vetor[3]=30;
    
    for(cont = 0; cont < tamanho ; cont++ ){
        printf(": %d\n", vetor[cont]);
    }

	return 0;
}