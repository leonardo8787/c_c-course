#include<stdio.h>
#include<stdlib.h>


void mostraSucessor(int numero){
	printf("\n O sucessor de %d é %d", numero , numero+1);
}

int retornaAntecessor(int numero){
	return numero - 1;
}

int main(){
	
	//definindo variáveis
	int a;

	printf("Digite um valor: ");
	scanf("%d",&a);

	mostraSucessor(a);
	printf("\n o antecessor de %d é %d", a, retornaAntecessor(a));
	retornaAntecessor(a);

	return 0;
}