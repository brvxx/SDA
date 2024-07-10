// vedi ragionamento su onenote

#include "reverse.h"

void ListReverse(Item* list) {
	Item* prev = NULL;
	Item* curr = list;
	Item* next = NULL;
	Item* tmp_1 = NULL;

	for (int i = 0; curr != NULL; i++) {
		// salviamo l'indirizzo dell'item in seconda posizione nella lista per evitare alla fine il loop
		if (i == 1) {
			tmp_1 = curr;
		}

		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	Item copy = *list;
	*list = *prev;
	*prev = copy;
	tmp_1->next = prev;

}

Item* Reverse(Item* list, int left) {
	Item* tmp = list;

	for (int i = 0; i < left; ++i) {
		if (ListIsEmpty(tmp)) {
			return list;
		}
		tmp = tmp->next;
	}
	if (ListIsEmpty(tmp)) {
		return list;
	}
	// al termine del processo tmp sarà un puntatore al primo item tra quelli da 
	// ivertire di ordine
	ListReverse(tmp);

	return list;
}