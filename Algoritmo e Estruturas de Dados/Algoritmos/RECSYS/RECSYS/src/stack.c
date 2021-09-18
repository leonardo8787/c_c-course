#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

Stack InitializeStack(){
    Stack p;
    p.base = (Bloco *)malloc(sizeof(Bloco));
    p.base->prox = NULL;
    p.top = p.base;
    p.size = 0;
    return p;
}

int IsEmptyStack(Stack *p){
    return (p->top == p->base);
}

int GetSizeStack(Stack *p){
    return p->size;
}

void Push(Item data, Stack *p){
    Bloco *aux;
    aux = (Bloco*)malloc(sizeof(Bloco));
    aux->data.key = data.key;
    aux->data.value = data.value;
    aux->prox = p->top;
    p->top = aux;
    p->size ++;
}

void Pop(Stack *p, Item *data){
    Bloco *aux;

    if (IsEmptyStack(p) == 1){
        printf ("[ERROR]: The stack is empty!\n");
        return;
    }

    aux = p->top;
    p->top = aux->prox;
    data->key = aux->data.key;
    data->value = aux->data.value;
    free(aux);
    p->size --;
}
 
void ShowStack(Stack *p){
    Stack aux;
    Item data; 
    
    if (IsEmptyStack(p) == 1){
        printf ("[ERRO]: The stack is empty!\n");
        return;
    }
    printf("__________________________________\n");
    printf("         STACK CONTENTS           \n");
    printf("__________________________________\n");
    aux = InitializeStack();
    while (IsEmptyStack(p) != 1){
        Pop(p, &data);
        printf("KEY:%d, VALUE:%d\n", data.key, data.value);
        Push(data, &aux);
    }
    
    while (IsEmptyStack(&aux) != 1){
        Pop(&aux, &data);
        Push(data, p);
    }
    printf("__________________________________\n");
    printf("SIZE:%d\n", p->size);
    printf("__________________________________\n");


    printf("\n");

}

void GetKItems(Stack *p, int k){
    Stack tmp;
    Item aux;
    tmp = InitializeStack();

    if(k > p->size){
        printf ("[ERROR]: The variable k is bigger than stack!\n");
        return;
    }

    for(int i=0; i<k; i++){
        Pop(p, &aux);
        Push(aux, &tmp);
    }

    *p = InitializeStack();
    for(int i=0; i<k; i++){
        Pop(&tmp, &aux);
        Push(aux, p);
    }

}

