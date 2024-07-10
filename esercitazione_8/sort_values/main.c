// variante dell'esercizio in cui non andiamo a cambiare i collegamenti della lista per far si che 
// gli item si trovino nell'ordine giusto, semplicemente lasciamo invariato l'ordine degli items della 
// lista ma cambiamo i valori all'iterno degli item. 
// 
// problema di questa implementazione? se per esempio abbiamo dei puntatori ai vari item della lista 
// questi perdono di senso perché verrà cambiato il valore al loro interno, mentre se lavorassimo con 
// i collegamenti tra gli item i puntatori ai vari items avrebbero ancora senso perché non modifichiamo 
// in nessun modo il campo value degli item 

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

	l1 = Sort(l1);
	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;

}