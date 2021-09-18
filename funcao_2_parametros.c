#include<stdio.h>
#include<stdlib.h>

void soma(int numero1, int numero2){
	printf("\nA soma de %d + %d = %d",numero1 , numero2, numero1 + numero2);
}

int main(){
	
	int a=1; int b=2;

	soma(a,b);

	return 0;
}