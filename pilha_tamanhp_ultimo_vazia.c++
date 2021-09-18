#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

bool pilha_vazia(int topo){
    if(topo == -1){
        return true;
    }else{
        return false;
    }
}

bool pilha_cheia(int topo){
    if(topo == TAM - 1){
        return true;
    }else{
        return false;
    }
}

int pilha_tamanho(int topo){
    return topo + 1;
}

void imprime_vetor(int vetor[TAM], int topo){
	int cont;
    cout<<endl<<endl;   
	for(cont=0; cont<TAM ; cont++){
		cout << vetor[cont] << " - ";
	}
	
	cout << "topo: " << topo << "Tamanho da Pilha: " << pilha_tamanho[topo] << endl;

}

void pilha_push(int pilha[TAM], int valor, int *topo){
	//caso não possa colocar mais valores
	if(pilha_cheia(*topo)){
		cout << "Pilha cheia!";
	}else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}
}

void pilha_pop(int pilha[TAM], int *topo){
    
    if(pilha_vazia(*topo)){
        cout << "A pilha já está vazia" << endl;
    }else{
        cout << "Valor Removido: " << pilha[*topo];
        *topo = *topo -1;
    }
    
}

void pilha_construtor(int pilha[TAM], int *topo){
    *topo = -1;
    
	int cont;
    cout<<endl<<endl;   
	for(cont=0; cont<TAM ; cont++){
		pilha[cont] = 0;
	}
}

int main(){
	
	int pilha[TAM];
	int topo; //topo da pilha
	
	pilha_construtor(pilha, &topo);
	
	imprime_vetor(pilha, topo);

	pilha_push(pilha, 5, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 7, &topo);
	imprime_vetor(pilha, topo);
	
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	
	pilha_pop(pilha, &topo);
	imprime_vetor(pilha, topo);

	return 0;
}