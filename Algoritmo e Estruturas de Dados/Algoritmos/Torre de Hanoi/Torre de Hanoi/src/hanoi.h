#ifndef HANOI_H 
#define HANOI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h" 


#define MINDISK 1

void como_jogar(char A, char B, char C, int n_disk);
void start_game(Pilha *A, Pilha *B, Pilha *C, int n_disk);
void tela(Pilha *A, Pilha *B, Pilha *C, int n_disk);
void jogar(Pilha *A, Pilha *B, Pilha *C, int n_disk);

#endif
