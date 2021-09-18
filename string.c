#include<stdio.h>
#include<stdlib.h>

void main(){

	//variáveis
	char palavra[255];

	printf("Digite uma palavra");

	//Limpa buffer
	setbuf(stdin, 0);

	//	LÊ a String 
	fgets(palavra, 255, stdin);

	palavra[strlen(palavra) - 1] = '\0'; 

	//imprime na tela
	printf("%s", palavra);

	system("pause");
}
