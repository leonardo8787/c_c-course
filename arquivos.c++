#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;

int main(){
	
	//Cursoe que irá percorre cada letra
	int c;
	char conteudoText[255];

	//Arquivo a ser lido
	FILE *file;

	//Abre o arquivo no diretório específico
	file = fopen("Text.txt", "r");

	//Se o arquivo for encontrado
	if(file){
		//contador
		int cont =0;

		//encontra letras, até o fim do arquivo;
		while((c = getc(file)) != EOF){
			printf("%c", c);
			//vetor de char que recebe letra atual
			conteudoText[cont] = c;

			cont++;
		}
		//fecha arquivo
		fclose(file);
	}

	//imprime conteúdo 
	for(int cont =0; cont< strlen(conteudoText) - 2; cont++ ){
		printf("%c", conteudoText[cont]);
	}

	return 0;
}