#include<stdio.h>
#include<stdlib.h>


#include "stack.h"
#include "matrix.h"
#include "vector.h"
#include "recsys.h"
#include "sort.h"


#define DATAPATH 	"dataset/netflix_tiny.csv"
#define USERPATH 	"dataset/user1.csv"
#define MAXCOLS		10
#define MAXROWS		10
#define KUSERS      3
#define KMOVIES     3	


int main(){
	Stack users, movies;
	int **mat;
	int *vet;

	//initialize structures 
	users   = InitializeStack();
	movies  = InitializeStack();
	mat 	= InitializeMatrix(MAXROWS, MAXCOLS);
	vet 	= InitializeVector(MAXCOLS);

	//prepare matrix
	GenerateFactorizeMatrix(DATAPATH, mat, MAXCOLS, MAXROWS);
	ShowMatrix(mat, MAXROWS, MAXCOLS);

	//prepare input vector
	GenerateInputVector(USERPATH, vet, MAXCOLS);
	ShowVector(vet, MAXCOLS);

	//get similar users 
	FindSimilarUsers(mat, vet, &users, MAXROWS, MAXCOLS);
	ComputeSimilarity(mat, &users, MAXROWS, MAXCOLS);
	ShowStack(&users);

	//sort stack data
	Sort(&users);
	GetKItems(&users, KUSERS);
	ShowStack(&users);

	//get k movies from k users in the stack
	FindSimilarMovies(&users, &movies, vet, mat, MAXCOLS);
	Sort(&movies);
	GetKItems(&movies, KMOVIES);
	ShowStack(&movies);


	
	return 0;
};


