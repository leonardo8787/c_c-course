#include "pilha.h"


void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, Item d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Item *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}


void PImprime(Pilha *p){
	for(int i=p->top-1; i>=p->base; i--)
		printf("%d\n", p->vet[i].val);
	printf("\n");
}






