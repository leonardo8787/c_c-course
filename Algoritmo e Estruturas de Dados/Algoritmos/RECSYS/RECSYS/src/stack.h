#ifndef STACK_H 
#define STACK_H

typedef struct tipoItem Item;
typedef struct tipoBloco Bloco;
typedef struct tipoStack Stack;

struct tipoItem{
    int value;
    int key;
};

struct tipoBloco{
    Item data;
    Bloco *prox;
};

struct tipoStack{
    Bloco *base;
    Bloco *top;
    int size;
};


Stack InitializeStack();
int   IsEmptyStack(Stack *p);
void  Push(Item dado, Stack *p);
void  Pop(Stack *p, Item *dado);
void  ShowStack(Stack *p);
int   GetSizeStack(Stack *p);
void  GetKItems(Stack *p, int k);


#endif