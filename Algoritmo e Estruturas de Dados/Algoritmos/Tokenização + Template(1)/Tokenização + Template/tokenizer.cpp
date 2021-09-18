#include "tokenizer.h"

int main(){

	char vet[] = "20.90, 200.119, 89.789, 45.9897";
	char sep[] = ", ' '"; //remove ',' e espaço em branco ' '
	Example<float> *toks = new Example<float>();


	toks->set_delimiter(sep);
	toks->tokenizer(vet);

	printf("\n%.2f\n", toks->get_token());

	
	toks->set_data(10);
	toks->set_data(20);
	toks->set_data(30);

	//exemplo de uma fila circular sem remoção em memória
	printf("==========================================\n");
	printf("\n%f\n", toks->get_data_without_removing());	
	printf("\n%f\n", toks->get_data_without_removing());	
	printf("\n%f\n", toks->get_data_without_removing());	
	printf("\n%f\n", toks->get_data_without_removing());
	printf("\n%f\n", toks->get_data_without_removing());
	printf("\n%f\n", toks->get_data_without_removing());
	printf("==========================================\n");

	//exemplo de fila com remoção de elementos
	printf("\n==========================================\n");
	printf("\n%f\n", toks->get_data_removing());	
	printf("\n%f\n", toks->get_data_removing());	
	printf("\n%f\n", toks->get_data_removing());	
	printf("\n%f\n", toks->get_data_removing());	
	printf("==========================================\n");

	printf("\n");
	return 0;

}