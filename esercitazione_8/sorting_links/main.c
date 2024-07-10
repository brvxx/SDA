// seconda versione dell'esercizio dell'ordinamento di una lista, questa volta andremo 
// ad ordinarla cambiando i vari next di ogni item nella lista, quindi senza toccare 
// il campo value degli item, andando solo a cambiare il collegamento tra questi. 
// Utilizzeremo il bubblesort come agloritmo di ordinamento perché risulta particolarmente 
// comodo perché le varie swap avveranno sempre tra item consecutivi e non faremo molta 
// fatica a gestire tutti i puntatori

#include "list.h"

extern Item* Sort(Item* i);

int main(void) {

	ElemType arr[] = {
		{.name = "Marco", .street = "via Yemen", .number = 22, .city = "Bologna", .province = "BO", .postal_code = "41120"},
		{.name = "Marcone", .street = "via Mogus", .number = 23, .city = "Napoli", .province = "FN", .postal_code = "41111"},
		{.name = "Aldonissimo", .street = "via Fructus", .number = 18, .city = "Brescia", .province = "BS", .postal_code = "41122"},
		{.name = "Fortnite", .street = "via Neri", .number = 88, .city = "Modena", .province = "MO", .postal_code = "41120"},
		{.name = "Caserta", .street = "via Inshallah", .number = 80, .city = "Varese", .province = "VA", .postal_code = "41103"}
	};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	l1 = Sort(NULL);
	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;

}