#include <iostream>
#include <new>

using namespace std;

void main(){
	
	int tamanho, cont;

	printf("Digite o tamanho: ");
	scanf("%d", &tamanho);

	int *vetor = new int(tamanho);

	for(cont = 0; cont < tamanho; cont++ ){
		vetor[cont] = cont;
		printf("\n%d", vetor[cont]);
	}
}