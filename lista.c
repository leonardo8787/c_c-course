#include <stdio.h>
#include <stdlib.h>
#include <new>


struct estrutura{
    int valorNumerico;
    struct estrutura *proximo;
};

int main(){
    
    printf("Lista\n");
    
    //cria inÌcio da lista
    estrutura *ponteiroEncadeado;
    
    //cria um novo valor 
    estrutura *novoPrimeiroValor = new estrutura;
    novoPrimeiroValor->valorNumerico = 13;
    novoPrimeiroValor->proximo = NULL;
    
    //printf("%d\n", novoPrimeiroValor->valorNumerico);
    
    //Faz o ponteiro da encadeada apontar para o primeiro valor 
    ponteiroEncadeado = novoPrimeiroValor;
    
    //Cria ums egundo valor 
    estrutura *novoSegundoValor = new estrutura;
    novoSegundoValor->valorNumerico = 20;
    novoSegundoValor->proximo = NULL;
    
    //printf("%d\n", novoSegundoValor->valorNumerico);
    
    ponteiroEncadeado->proximo = novoSegundoValor;
    
    while(ponteiroEncadeado != NULL){
        //Imprime o valor atual
        printf("\nValor: %d", ponteiroEncadeado->valorNumerico);
        //
        ponteiroEncadeado = ponteiroEncadeado->proximo;
    }
    
    return 0;
}