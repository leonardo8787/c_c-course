#ifndef MATRIX_H 
#define MATRIX_H
#include "stack.h"


int** InitializeMatrix(int maxcols, int maxrows);
void  GenerateFactorizeMatrix(char *path, int **mat, int maxcols, int maxrows);
void  ShowMatrix(int **mat, int maxrows, int maxcols);

#endif

