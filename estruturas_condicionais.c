#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    setlocale(LC_ALL, "");
    
    int a=9;
    int b=8;
    char c='x';
    
    if(a == 9){
        printf("A variável 'a' = 9");
    } else {
        printf("A variável 'a' não é igual a 9");
    }
    
    if(a % 2 == 1){
        printf("\n A variável 'a' é ímpar");
    } else {
        printf("\n A variável 'b' é par");
    }
    
    if(c == 'x'){
        printf("A variável c = x");
    }else{
        printf("A variável c != x");
    }
    
}
