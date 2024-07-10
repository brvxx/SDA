#include "list.h"

int Len(const Item* i) {
	int len; 
	for(len = 0; !ListIsEmpty(i); i = ListGetTail(i), ++len ){}
	return len; 
}

Item* Sort(Item* i) {
	// item fittizio statico che ha come valore successivo la vera testa della nostra lista, questo ci sarà di grande 
	// aiuto per effettuare una swap tra un elemento in testa alla lista e il suo successivo, se no dovremmo trattare 
	// quel caso a parte, poiché l'istruzione prev->next = foll non avrebbe senso
	Item head = { .next = i };
	int dim = Len(i); 
	bool sorted = false;  // flag del bubble sort 

	while (!sorted) {
		sorted = true; 

		Item* prev = &head; 
		Item* curr = prev->next;

		for (int j = 0; j < dim - 1; ++j) {
			Item* foll = curr->next; 
			Item* follfoll = foll->next; 
			
			// se il valore dell'item corrente è maggiore del successivo allora swappiamo 
			// mettendo apposto i vari next degli item
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(foll)) > 0) {
				// mettiamo apposto i vari next 
				prev->next = foll; 
				foll->next = curr; 
				curr->next = follfoll; 

				// mandiamo avanti curr e prev (nota che se avviene lo swap, curr è già nella sua posizione) 
				prev = foll; 

				// aggiorniamo la flag
				sorted = false; 
			}
			else {
				prev = curr; 
				curr = foll; 
			}
		}
		dim--; 
	}
	return head.next; 
}