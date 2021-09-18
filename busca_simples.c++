#include<iostream>
#include<stdio.h>
#include<new>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){
	
	int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
	int valorProcurado;
	int posicao;
	int cont;
	bool valorFoiEncontrado;

	for(cont=0;cont<TAM;cont++){
		cout << vetor[cont] << " - ";
	}

	printf("\nQual número deseja encontrar? ");
	scanf("%d", &valorProcurado);

	//Percorre a lista em busca do valor
	for(cont=0;cont<TAM;cont++){
		if(vetor[cont] == valorProcurado){
			valorFoiEncontrado = true;
			posicaoEncontrada = cont;
			//cout << "O valor foi encontrado: " << cout;

		}
	}

	if(valorFoiEncontrado){
		cout<<"O valor foi encontrado na posição: "<< posicaoEncontrada;
	}else{
		cout<<"Valor não encontrado";
	}

	return 0;
}