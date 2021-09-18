#include<stdio.h>
#include<string>
#include<iostream>
#include<new>

using namespace std;

struct fruta{
	string cor;
	string nome;
};

int main() {
	
	//Criando um ponteiro para o struct criado
	fruta *primeiraFruta = new fruta;

	//Modificando valores
	primeiraFruta->cor = "Amarela";
	primeiraFruta->nome = "Banana";

	//Exibindo Valores
	cout << "Fruta: " << primeiraFruta->nome << ", Cor: " << primeiraFruta->cor;
	
	fruta *ponteiroListaDeFrutas = new fruta[2];
	
	ponteiroListaDeFrutas[0].cor = "Vermelho";
	ponteiroListaDeFrutas[1].cor = "Morango";
	ponteiroListaDeFrutas[0].cor = "Verde";
	ponteiroListaDeFrutas[1].cor = "Kiwi";

	//Percorrendo e exibindo
	int cont;
	for(cont=0; cont<2 ; cont++){
		//Exibindo valores
		cout << "Fruta: " << ponteiroListaDeFrutas[cont].nome << ", Cor: " << ponteiroListaDeFrutas[cont].cor;
	}

	return 0;
}