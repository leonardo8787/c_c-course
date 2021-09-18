#include<stdio.h>
#include<string.h>
#include<fstream>
#include<string.h>
#include<iostream>

using namespace std;

int main() {
	
	//Dizer qual arquivo lido
	ifstream input("Vocabulario.txt");

	//String que receberá o texto lido
	string textoLido;

	//Passa o texto do arquivo para a string 
	for(string line; getline(input, line);){
		textoLido += line;
	}

	//Mostra o conteúdo
	cout << textoLido;

	return 0;
}