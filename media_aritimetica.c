#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    float a, b;
    float result;
    setlocale(LC_ALL, "");
    printf("Digite um valor: ");
    scanf("%f", &a);
    printf("\nDigite um valor: ");
    scanf("%f", &b);
    result=((a+b)/2);
    printf("Amédia dos valores é: %f", result);
}
