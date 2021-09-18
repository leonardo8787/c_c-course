#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void main(){

  setlocale(LC_ALL, "");	
	
  char letra = 'x';
  
  if(letra == 'x'){
    printf("\n A letra é x.");
  }
  printf("\nCódigo da letra = %d", letra);
  
  system("pause");
}
