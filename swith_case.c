#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){
 setlocale(LC_ALL,"");
 int a;
 printf("Digite um número de 1 a 3");
 scanf("%d", &a);
 
 switch(a){
 	case 1:
 		printf("vc digitou 1");
 	    break;
 	case 2:
 		printf("vc digitou 2");
 	    break;
 	case 3: 
 		printf("vc digitou 3");
 	    break;
 	default:
 		printf("digite um número válido");
 }
}
