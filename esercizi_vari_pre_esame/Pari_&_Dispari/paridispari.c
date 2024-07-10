#include "list.h"

Item* PariDispari(Item* i) {
	Item* pari_head = NULL; 
	Item* dispari_head = NULL; 
	Item* last_pari = NULL; 
	Item* last_dispari = NULL; 

	while (!ListIsEmpty(i)) {
		if (i->value % 2 == 0) {
			if (ListIsEmpty(pari_head)) {
				pari_head = i;
			}
			else {
				last_pari->next = i;
			}
			last_pari = i;
		}
		else {	// caso in cui il valore è dispari (i->value % 2 != 0) 
			if (ListIsEmpty(dispari_head)) {
				dispari_head = i;
			}
			else {
				last_dispari->next = i;
			}
			last_dispari = i;
		}

		i = ListGetTail(i); 
	}

	if (ListIsEmpty(pari_head)) {
		return dispari_head; 
	}
	if (!ListIsEmpty(pari_head) && !ListIsEmpty(dispari_head)) { // colleghiamo tra loro pari e dispari
		last_pari->next = dispari_head;
		last_dispari->next = NULL; 
	}
	return pari_head; 
}