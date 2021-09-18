#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

int main(){

	//Variável
	int a = 20;

	//imprimindo o valor de uma variável
	cout << "Valor de a = " << a << endl;
	cout << "endereco de a = " << &a << endl;

	//variáveis armazenam valores
	int b=10;
	//ponteiros armazenam posições da memória
	int *ponteiro;
	ponteiro = &b;
	//ponteiro recebendo a posição na mémoria da b
	cout << "Valor de b = " << b << endl;
	cout << "endereco de b = " << &b << endl;
	*ponteiro = 40;
	cout << "Valor de b = " << b << endl;
	//scanf("%d", &a);

	return 0;
}