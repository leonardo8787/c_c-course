
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   Tokenizer em C. 
   Neste exemplo, utilizamos a chamada de função strtok, incluída na string.h.
   A strtok recebe dois parâmetros, a string a ser quebrada e os possíveis separadores. 
   Utilizamos como único separador a virgula. Porém, pode-se declarar sep com vários tipos.
   Por exemplo, const char sep[2] = ",' '";. Note que utilizamos ' ' para tratar espaços em branco. 

   A função strtok:
    A função strtok, se baseia em objetos C cujo resultado da execução cria um iterator.
    Um iterator, nada mais é que um ponteiro que pode caminhar entre múltiplos itens.
    Então, dentro do while, para não sobrepormos os tokens criados, passamos NULL como
    primeiro parâmetro. Nesse caso, o strtok fica retornando token por token até finalizar
    o conjunto. 

   Nota:
     A variável que guarda a palavra deve ser suficientemente grande para armazenar uma linha toda.
     Caso contrário, poderá obter resultados inesperados com a execução.
*/

int main(){

    char palavra[50] = {"20.90,200.119,89.789,45.9897"};
    char *pt;
    const char sep[1] = ",";

    pt = strtok(palavra, sep);
    while(pt){
        printf("token: %s\n", pt);
        pt = strtok(NULL, sep);
    }

    return 0;
}