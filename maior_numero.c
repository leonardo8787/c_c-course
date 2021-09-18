#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    
    setlocale(LC_ALL, "");
    
    int a, b;
    int comparador;
    
    printf("---Mostra maior número---\n\n");
    printf("Digite um número: ");
    scanf("%d\n", &a);
    printf("Digite outro número: ");
    scanf("%d\n", &b);
    
    if(a > b){
        printf("%d é maior que %d", a, b);
    } else if(b > a) {
        printf("%d é maior que %d", b, a);
    } else {
        printf("os números digitados são iguais");
    }
    
}
