//operações com listas encadeadas
#include<iostream>
#include<new>
#include<string>
#include<stdlib.h>

using namespace std;

struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

void limpaTela(){
    system("clear || cls");
}

int retornaTamanho(pessoa *ponteiroEncadeada){
    int tamanho=0;
    pessoa *p = ponteiroEncadeada;
    while(p != NULL){
        p=p->proximo;
        tamanho++;
    }
    return tamanho;
}

void ImprimiEncadeada(pessoa *ponteiroEncadeada){
    pessoa *p = ponteiroEncadeada;
    while(p != NULL){
        cout<<p->nome<<","<<p->rg<<endl;
        p=p->proximo;
    }
}

adoComecoEncadeada(pessoa *&ponteiroEncadeada,string nome,int rg){
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = ponteiroEncadeada;
    
    ponteiroEncadeada = novoValor;
    
}

int main(){
    
    int funcaoDesejar=1;
    pessoa *ponteiroEncadeada= new pessoa;
    
    /*pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "john";
    novoPrimeiroValor->rg = 123;
    novoPrimeiroValor->proximo=NULL;
    
    ponteiroEncadeada = novoPrimeiroValor;
    
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "alex";
    novoSegundoValor->rg = 456;
    novoSegundoValor->proximo=NULL;
    
    novoPrimeiroValor->proximo = novoSegundoValor;*/
    
    while(funcaoDesejar < 9 && funcaoDesejar > 0){
        cout<<"Tamanho atual: "<<retornaTamanho(ponteiroEncadeada)<<endl;
        cout<<"Operações"<<endl;
        cout<<"1 - Inserção de um node no inicio da lista"<<endl;
        cout<<"2 - Inserção de um node no fim da lista"<<endl;
        cout<<"3 - Inserção de um node na posição N"<<endl;
        cout<<"4 - Retirar um node do inicio da lista"<<endl;
        cout<<"5 - Retirar um node no fim da lista"<<endl;
        cout<<"6 - Retirar um node na posição N"<<endl;
        cout<<"7 - Procurar um node com o campo RG"<<endl;
        cout<<"8 - Imprimir a Lista."<<endl;
        cout<<"9 - Sair do sistema."<<endl;
        cout<<"\nEscolha um numero e pressione ENTER: \n"<<endl;
        ImprimiEncadeada(ponteiroEncadeada);
        cin >> funcaoDesejar;
        
        limpaTela();
        
        string nome;
        int rg;
        
        switch(funcaoDesejar){
            case 1:
                cout<<"Inserção de um node no inicio da lista"<<endl;
                cout<<"\nDigite o nome: ";
                cin>>nome;
                cout<<"\nDigite o RG: ";
                cin>>rg;
                adoComecoEncadeada(ponteiroEncadeada, nome, rg);
                break;
            case 2:
                cout<<"Inserção de um node no fim da lista"<<endl;
                break;
        }
    }
    
    
    return 0;
}