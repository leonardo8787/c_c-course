#include<stdio.h>
#include<stdlib.h>

void imprimeVetor(int *vetor, int tamanho){
	
	//variavel contador
	int i;

	//percorrendo vetor
	for(i=0; i<3; i++){
		printf("%d \n",vetor[i]);
	}

}

void modificaVetor(int *vetor, int tamanho){
	//variavel contador
	int i;

	//percorrendo vetor
	for(i=0; i<3; i++){
		printf(": %d \n",vetor[i]+1);
	}
}

int main(){
	
	//Definindo Vetor
	int v[3] = {1,2,3};

	//mostrando vetor
	imprimeVetor(v, 3);
	modificaVetor(v, 3);

	//retorno da função
	return 0;

}