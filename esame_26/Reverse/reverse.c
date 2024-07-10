#include "reverse.h"

Item* ListReverse(Item* list) {
	Item* prev = NULL;
	Item* curr = list;
	Item* next = NULL;

	while (!ListIsEmpty(curr)) {
		// salviamo nel puntatore a item la posizione successiva alla corrente 
		next = curr->next;

		// invertiamo il collegamento tra item
		curr->next = prev;

		// ci spostiamo alla prossima coppia di items
		prev = curr;
		curr = next;
	}
	return prev; 
}

Item* Reverse(Item* list, int left) {
	if (left <= 0) {
		return ListReverse(list); 
	}

	Item* tmp = list; 
	// facciamo puntare a tmp il primo elemento della lista tra quelli da reversare 
	for (int i = 0; i < left - 1; ++i) {
		if (ListIsEmpty(tmp)) {
			return list; 
		}
		tmp = ListGetTail(tmp); 
	}
	// mettiamo apposto il caso in cui esca dal while con una lista null
	if (ListIsEmpty(tmp)) {
		return list; 
	}
	tmp->next = ListReverse(tmp->next); 

	return list; 
}