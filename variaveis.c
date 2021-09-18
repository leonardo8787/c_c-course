#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
    //permite acessar acentos
    setlocale(LC_ALL,"");
    
    //variaveis
    int a=5;
    int b=6;
    float c;
    char letra='t';
    
    printf("%d\n", a+b);
    printf("O valor 'a' é: %d\n", a);
    printf("Digite o novo valor de A: ");
    scanf("%d", &a);
    printf("O novo valor de A é: %d", a);
    
    printf("\nDIgite um valor float: \n");
    scanf("%f", &c);
    printf("\n O valor do número float é: %f", c);
    getchar();
    printf("\n\n");
    printf("A letra é: %c", letra);
    fflush(stdin); //limpa o buffer, memória temporária de leitura
    printf("\nDigite uma nova letra: ");
    scanf("%c", &letra);
    printf("\nA letra é: %c", letra);
}
