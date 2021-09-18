#include<stdio.h>
#include<stdlib.h>
#include "recsys.h"


void FindSimilarUsers(int **mat, int *user, Stack *p, int maxrols, int maxcols){
	Item aux;

	for(int i=0; i<maxrols; i++)
		for(int j=0; j<maxcols; j++)
			if((user[j] != 0) && (mat[i][j] != 0)){
				aux.key = i;
				aux.value = 0;
				Push(aux, p);
				break;
			}
}

void ComputeSimilarity(int **mat, Stack *p, int maxrols, int maxcols){
	int *tmp;
	Stack aux;
	Item data;

	aux = InitializeStack();

	while(IsEmptyStack(p) != 1){
		Pop(p, &data);
		for(int j=0; j<maxcols; j++){
			data.value += mat[data.key][j];
		}
		Push(data, &aux);
	}

	while(IsEmptyStack(&aux) != 1){
		Pop(&aux, &data);
		Push(data, p);
	}
}


void  FindSimilarMovies(Stack *u, Stack *m, int *vet, int **mat, int maxcols){
	Item aux;
	int values[maxcols];

	for (int i=0; i<maxcols; i++)
		values[i] = 0;

	while(IsEmptyStack(u) != 1){
		Pop(u, &aux);
		for(int j=0; j<maxcols; j++)
			if((mat[aux.key][j] != 0) && (vet[j] == 0))
				if(values[j] < mat[aux.key][j])
					values[j] = mat[aux.key][j];
	}

	for(int i=0; i<maxcols; i++)
		if(values[i] > 0){
			aux.key = i;
			aux.value = values[i];
			Push(aux, m);
		}

}







