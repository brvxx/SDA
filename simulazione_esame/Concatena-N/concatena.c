#include "doublelist.h"

Item* DlistGetLast(Item* i) {
	if (DListIsEmpty(i)) {
		return NULL; 
	}

	while (!DListIsEmpty(DListGetTail(i))) {
		i = DListGetTail(i); 
	}

	return i; 
}

Item* ConcatenaN(Item** v, size_t v_size) {
	
	Item* head = NULL; // puntatore alla testa della lista concatenata 
	Item* last = NULL; // puntatore che verrà aggiornato per puntare sempre 
					   // all'ultimo item dell'ulitma lista concatenata

	for (size_t i = 0; i < v_size; ++i) {
		if (!DListIsEmpty(v[i])) {
			if (head == NULL) {
				head = v[i]; 
			}
			else {
				// Se la testa non è NULL, ciò significa che last non sarà MAI 
				// NULL, perchè abbiamo già incontrato una lista non NULL nella sequenza, quindi 
				// sarà possibile dereferenziarlo per mettere apposto i collegamenti 

				last->next = v[i]; 
				v[i]->prev = last; 
			}

			// last va aggiornato sempre a prescindere che sia la prima lista non NULL o 
			// qualsiasi altra 
			last = DlistGetLast(v[i]); 
		}
	}

	return head; 
}