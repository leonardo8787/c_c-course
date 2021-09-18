#include<iostream>
#include<stdlib.h>
#include<string>

#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]){
    int i;
    cout << "\n";
    for(i=0;i<TAM;i++){
        cout<<" |"<<vetor[i]<<"| ";
    }
}

void bubble_sort(int vetor[TAM]){
    int aux;
    int y;
    for(int x=0; x< TAM; x++){
        imprimeVetor(vetor);
        for(y=x+1; y<TAM; y++){
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x]=vetor[y];
                vetor[y]=aux;
            }
        }
    }
}

int main(){
    
    int vetor[TAM]={10,9,8,7,6,5,4,3,2,1};
    
    bubble_sort(vetor);
    
    imprimeVetor(vetor);
    
    return 0;
}