#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    //permite acessar acentos
    setlocale(LC_ALL,"");
    printf("Olá");
}
