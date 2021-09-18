#ifndef MAT_H 
#define MAT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAXCOLS 7
#define MAXROWS 7

typedef struct Item{
	int val;
}Item;

typedef struct Matrix{
	Item m[MAXROWS][MAXCOLS];
}Matrix;


void Initialize(Matrix *mat);
void  CalcPath(Matrix *mat);
void Imprime(Matrix *mat);

#endif