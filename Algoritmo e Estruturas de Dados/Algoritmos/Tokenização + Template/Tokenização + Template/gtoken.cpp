#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*
	Tokenizer em C++.
	Neste exemplo utilizamos os mesmos princípios apresentados no arquivo gtoken.c.
	Para mais informações sobre a strtok, olhe os comentários desse outro arquivo.
*/
int main(){
	
	char vet[] = "20.90, 200.119, 89.789, 45.9897";
	const char sep[] = ", ' '"; //remove ',' e espaço em branco ' '
	char *tokens;
	float data;
	string::size_type st; // alias of size_t

	tokens = strtok(vet, sep);

	printf("\n");
	while(tokens != NULL){

		printf("TOKEN STRING: %s\n", tokens);

		data = stod(tokens, &st);

		printf("TOKEN FLOAT: %.2f\n", data);

		tokens = strtok(NULL, sep);
	}

	printf("\n");
	return 0;
}