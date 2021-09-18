#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;

int main() {
	
	//Cria o objeto de arquivo
	ofstream arquivoDeSaida;

	//Abre o arquivo ou cria caso não exista
	arquivoDeSaida.open("Text.txt", std::ios_base::app);

	//Escreve algo
	arquivoDeSaida << "Mamãezinha";

	//Fecha o arquivo
	arquivoDeSaida.close();

	return 0;
}