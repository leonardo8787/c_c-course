#include<stdio.h>
#include<stdlib.h>
#include "vector.h"

int* InitializeVector(int maxcols){ 
	int *vetor;
	vetor = (int *)malloc(maxcols * sizeof(int*));
	for(int i=0; i<maxcols; i++){
		vetor[i] = 0;
	}

	return vetor;
}

void GenerateInputVector(char *userpath, int *vetor, int maxcols){
	FILE *user;
	int movie;
	int rating;
	char u1;

	user = fopen(userpath, "r");
	if ((user == NULL) || (maxcols == 0)){
		printf("[ERROR]: Fail to open file or vector doesn't initialized correctly!\n");
		return;
	}

	while ((fscanf(user, "%d %c %d \n", &movie, &u1, &rating)) != EOF){
		if (movie < maxcols){
			vetor[movie] = rating;
		}
	}
	fclose (user);
}

void ShowVector(int* vetor, int maxcols){

	printf("__________________________________________________________________________\n");
	printf("                             USER RATINGS                                 \n");
	printf("__________________________________________________________________________\n");
	for(int i=0; i < maxcols; i++){
		printf("%d\t", vetor[i]);
	}
	printf("\n");
	printf("__________________________________________________________________________\n");
	printf("\n");

}
