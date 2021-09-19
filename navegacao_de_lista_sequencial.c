#include <stdio.h>
#include <stdlib.h>
#include <new>

#define TAM 3 

//aloca um vator do tamanho pedido
int* alocaVetor(int tam){
    //cria um ponteiro
    int *v;
    //aloca memória para o novo vetor 
    v = (int *) malloc(tam * sizeof(int));
    return v;
}

void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial){
    int cont;
    for(cont =0; cont<tamanhoDaListaSequencial; cont++){
        printf("\nValor %d: %d", cont, vetor[cont]);
    }
}

int main(){
    
    int vetor[TAM] = {1,2,3}, cont , tamanhoDaLista;
    
    for(cont=0;cont<TAM;cont++){
        printf("\nValor %d: %d", cont, vetor[cont]);
    }
    
    imprimeSequencial(vetor, 3);
    
    //lendo novos valores
    for(cont=0; cont<TAM;cont++){
        scanf("%d", &vetor[cont]);
    }
    
    imprimeSequencial(vetor, 3);
    
    //pedindo tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoDaLista);
    
    //ponteiro para o novo vetor 
    int *vetorLidoNaHora;
    
    //Passa o espaço da memória que foi criado para o vetor 
    vetorLidoNaHora = alocaVetor(tamanhoDaLista);
    
    //Lendo novos valores
    for(cont=0; cont<tamanhoDaLista; cont++){
        scanf("%d", &vetorLidoNaHora[cont]);
    }
    imprimeSequencial(vetorLidoNaHora, tamanhoDaLista);
    
    //criando em c++
    int *vetorEmPlusPlus = new int[5];
    
    //lendo 
    for(cont=0; cont<5; cont++){
        scanf("%d", &vetorEmPlusPlus[cont]);
    }
    return 0;
}