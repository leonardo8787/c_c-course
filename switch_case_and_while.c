#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
	int opcao;

	while(opcao < 1 || opcao > 3){
		printf("Escolha uma opção: \n");
		printf("\n1-opção 1");
		printf("\n1-opção 2");
		printf("\n1-opção 3");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("\nOpção 1 escolhida");
				break;
			case 2:
				printf("\nOpção 2 escolhida");
				break;
			case 3:
				printf("\nOpção 3 escolhida");
				break;
			default:
				printf("\nEscolha uma opção válida");
				break;
		}
		system("pause");
	}
}