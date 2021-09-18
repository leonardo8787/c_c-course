//alocãção dinâmica de matrizes.c

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int linhas = 3, colunas = 3;
	int **matriz;

	matriz = (int **) malloc(linhas * sizeof(int *));

	//aloca
	for(int i=0; i<linhas; i++){
		matriz[i] = (int *) malloc(colunas * sizeof(int));
	}

	//preenche e exibe a matriz
	for(int i=0; i<linhas; i++){
	    printf("\n");
		for(int j=0; j<colunas; j++){
			matriz[i][j]=i;
			printf(" %d ", matriz[i][j]);
		}
	}

	return 0;
}