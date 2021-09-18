#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    
    int a, b;
    int resultado;
    
    setlocale(LC_ALL, "");
    
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("\nDigite um valor: ");
    scanf("%d", &b);
    resultado = a - b;
    printf("O resultado absoluto é: %d", abs(resultado));
}
