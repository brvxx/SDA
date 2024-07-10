#include <stdlib.h>

#include "remove.h"

Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL; 
	}

	Item* prev = i; 
	Item* curr = i->next; 
	Item* next = curr->next; 
	while (!ListIsEmpty(curr)) {
		if (ElemCompare(ListGetHeadValue(prev), ListGetHeadValue(curr)) == 0) {
			prev->next = next;
			
			free(curr); 
			ElemDelete(&curr->value);
			
			curr = next; 
			if (curr != NULL) {
				next = curr->next; 
			}
		}
		else {
			prev = curr;
			curr = next; 
			if (curr != NULL) {
				next = curr->next;
			}
		}
	}
	return i; 
}

// nota che la funzione implementata ha complessità O(n), dove n è il numero di item contenuti nella lista, infatti abbiamo 
// un unico ciclo che gira scorrendo ogni elemento della lista, il blocco di comandi al suo interno ha complessità fissa (costante) 
// quindi non influisce sulla complessità della funzione. 