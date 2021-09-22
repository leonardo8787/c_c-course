#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>

void main() {
  bool a=true, b=false;
  if(a == true){
    printf("A é verdadeiro");
  }
  if(b){
    printf("\n B é verdadeiro");
  }
  if(!b){
    printf("\n B é falso");
  }
  system("pause");
}

