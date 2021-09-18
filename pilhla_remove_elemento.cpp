//pilha desempilhar

#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM], int topo){
	int cont;
    cout<<endl<<endl;   
	for(cont=0; cont<TAM ; cont++){
		cout << vetor[cont] << " - ";
	}
	
	cout << "topo: " << topo << endl;

}

void pilha_push(int pilha[TAM], int valor, int *topo){
	//caso não possa colocar mais valores
	if(*topo == TAM - 1){
		cout << "Pilha cheia!";
	}else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}
}

void pilha_pop(int pilha[TAM], int *topo){
    
    if(*topo == -1){
        cout << "A pilha já está vazia" << endl;
    }else{
        cout << "Valor Removido: " << pilha[*topo];
        *topo = *topo -1;
    }
    
}

int main(){
	
	int pilha[TAM]={0,0,0,0,0,0,0,0,0,0};
	int topo; //topo da pilha

	pilha_push(pilha, 5, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 7, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_pop(pilha, &topo);
	imprime_vetor(pilha, topo);

	return 0;
}