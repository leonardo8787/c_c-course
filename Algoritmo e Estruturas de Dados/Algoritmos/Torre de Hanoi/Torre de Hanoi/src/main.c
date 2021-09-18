#include "hanoi.h"

int main(){
	Pilha A, B, C;

	//como_jogar('A', 'B', 'C', 3);
	start_game(&A, &B, &C, 3);
	jogar(&A, &B, &C, 3);

	return 0;
}