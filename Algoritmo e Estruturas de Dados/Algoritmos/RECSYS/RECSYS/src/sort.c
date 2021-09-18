#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


void swap(Item *a, Item *b){
	Item aux = *a;
	*a = *b;
	*b = aux;
}

void partition(Item *v, int p, int r, int *i, int *j){
	int pivo;
	int idx = (p+r)/2;
	*i = p;
	*j = r;
	pivo = v[idx].value;
	
	do{
		while(v[*i].value < pivo && *i < r)
			*i = *i + 1;
		while(v[*j].value > pivo && *j > p)
			*j = *j - 1;
		if(*i<=*j){
			swap(&v[*i], &v[*j]);
			*i = *i + 1;
			*j = *j - 1;
		}

	}while(*i<=*j);
	
}

void quickSort(Item *v, int p, int r, int i, int j){
	partition(v, p, r, &i, &j);
	if(j > p)
		quickSort(v, p, j, i, j);
	if(i < r)
		quickSort(v, i, r, i, j);
}


void Sort(Stack *p){
	Item v[GetSizeStack(p)];
	int i = 0;
	int psize = GetSizeStack(p);

	while(IsEmptyStack(p) != 1){
		Pop(p, &v[i]);
		i++;
	}	

	quickSort(v, 0, psize-1, 0, 0);

	for(i=0; i<psize; i++)
		Push(v[i], p);

}









