#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool retornaBooleano(){
	return false;
}

int main(){
	
	bool variavelBooleano;

	variavelBooleano = retornaBooleano();

	printf("%d", variavelBooleano);

	return 0;
}