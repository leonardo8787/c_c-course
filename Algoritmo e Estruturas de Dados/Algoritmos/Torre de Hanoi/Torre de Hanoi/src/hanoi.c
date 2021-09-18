#include "hanoi.h"


void como_jogar(char A, char B, char C, int n_disk){
	if(n_disk>0){
		como_jogar(A, C, B, n_disk-1);
		printf("Mova o disco do topo de %c para %c \n", A, C);
		como_jogar(B, A, C, n_disk-1);
	}
}


void start_game(Pilha *A, Pilha *B, Pilha *C, int n_disk){
	Item d;

	if(n_disk > MAXTAM){
		printf("TAMANHO MUITO GRANDE!!!");
	}else{
		FPVazia(A);
		FPVazia(B);
		FPVazia(C);

		for(int i=n_disk; i>0; i--){
			d.val = i;
			PUSH(A, d);
		}
	}
}


void tela(Pilha *A, Pilha *B, Pilha *C, int n_disk){
	int v1, v2, v3;

	system("cls || clear");
	
	for(int i=n_disk-1; i>=0; i--){
		v1 = (A->top > i)?A->vet[i].val:0;
		v2 = (B->top > i)?B->vet[i].val:0;
		v3 = (C->top > i)?C->vet[i].val:0;
		printf("[%d]\t[%d]\t[%d]\n",v1, v2, v3);
	}

	printf("A\tB\tC\n");
	printf("%d\t%d\t%d\n", A->top, B->top, C->top);
}

void jogar(Pilha *A, Pilha *B, Pilha *C, int n_disk){
	bool notmov = false;
	Pilha *Origem, *Destino;
	int mov = 0;
	char o,d;
	Item disk;

	while(C->top != n_disk){

		tela(A, B, C, n_disk);
		
		if(notmov)
			printf("Movimento de %c para %c incorreto\n",o,d);
		else
			mov ++;

		notmov = false;
		printf("Digite a origem [A,B,C]:");
		scanf(" %c", &o);
		printf("Digite o destino [A,B,C]:");
		scanf(" %c", &d);

		//define vetores de origem / destino
		Origem  = (o=='A')?A:Origem;
		Origem  = (o=='B')?B:Origem;
		Origem  = (o=='C')?C:Origem;
		Destino = (d=='A')?A:Destino;
		Destino = (d=='B')?B:Destino;
		Destino = (d=='C')?C:Destino;

		
		if(Destino->top == Destino->base || Origem->vet[Origem->top - 1].val < Destino->vet[Destino->top - 1].val){
			POP(Origem, &disk);
			PUSH(Destino, disk);
		}else
			notmov = true;

	}

	tela(A, B, C, n_disk);
	printf("WINNER !!! :)\n");
	printf("MOVIMENTOS REALIZADOS %d\n", mov);

}




