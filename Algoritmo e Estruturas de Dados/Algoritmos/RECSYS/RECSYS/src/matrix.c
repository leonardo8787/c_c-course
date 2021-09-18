#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"


int** InitializeMatrix(int maxcols, int maxrows){
	int **mat = (int **)malloc(maxrows * sizeof(int*));
	for(int i=0; i<maxrows; i++){
		mat[i] = (int*)malloc(maxcols * sizeof(int));
		for(int j=0; j<maxcols; j++)
			mat[i][j] = 0;
	}
	
	return mat;
}


void ShowMatrix(int **mat, int maxrows, int maxcols){
	printf("__________________________________________________________________________\n");
	printf("                            FACTORIZE MATRIX                              \n");
	printf("__________________________________________________________________________\n");
	for(int i=0; i<maxrows; i++){
		for(int j=0; j<maxcols; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	printf("__________________________________________________________________________\n");
	printf("__________________________________________________________________________\n");
	printf("\n");
}


void GenerateFactorizeMatrix(char *path, int **mat, int maxcols, int maxrows){
	FILE *fp;
	int user, movie, rating;
	char v1, v2;

	fp = fopen(path, "r");
	
	if (fp == NULL){
		printf("[ERROR]: Fail to open file!\n");
		return;
	}

	while((fscanf(fp, "%d %c %d %c %d\n", &user, &v1, &movie, &v2, &rating)) != EOF){
		if(user < maxrows && movie < maxcols){
			mat[user][movie] = rating;
		}
	}

	fclose(fp);
}


