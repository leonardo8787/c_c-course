#include<stdio.h>
#include<stdlib.h>

int retornaDez();

int main(){
	int a;

	a=retornaDez();

	printf("%d", a);

	return 0;
}

int retornaDez(){
	printf("\n Oi galera! \n");
	return 10;
}