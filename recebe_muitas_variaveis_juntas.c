#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    setlocale(LC_ALL, "");
    
    int a,b,c,resultado;
    printf("Digite 3 números: ");
    scanf("%d %d %d", &a, &b, &c);
    resultado = a*b*c;
    printf("resultado: %d", resultado);
}
