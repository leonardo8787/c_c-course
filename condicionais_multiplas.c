#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
void main() {
setlocale(LC_ALL,"");
 int a =10;
 if(a>5 && a<15){ // and
   printf("\nA variável 'a' está entre 5 e 15");
 }
 if(a>5 || a<15){ // or
   printf("\nA variável 'a' está entre 5 e 15");
 }
 if((a>5 && a<15) || a == 20 ){
   printf("\nA variável 'a' está entre 5 e 15");
 }
 system("pause");
}
