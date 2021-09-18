#include<stdio.h>
#include<stdlib.h>

char retornaCaractere();

int main(){
	char letra;

	letra = retornaCaractere();

	printf("%c", letra);

	return 0;
}

char retornaCaractere(){
	return 'x';
}