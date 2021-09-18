#ifndef MATRIX_H 
#define MATRIX_H

#include "stack.h"

void  FindSimilarUsers(int **mat, int *user, Stack *p, int maxrols, int maxcols);
void  ShowSimilarUsers(Stack *p);
void  ComputeSimilarity(int **mat, Stack *p, int maxrols, int maxcols);
void  FindSimilarMovies(Stack *u, Stack *m, int *vet, int **mat, int maxcols);

#endif

