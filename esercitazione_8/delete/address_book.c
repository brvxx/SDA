#include <stdlib.h>

#include "list.h"

Item* Delete(Item* i, const char* name) {
	Item* tmp = i; 
	Item* prev = NULL; 

	while (!ListIsEmpty(tmp)) {
		if (strcmp(tmp->value.name, name) == 0) {
			break; 
		}
		prev = tmp; 
		tmp = ListGetTail(tmp);
	}
	// se abbiamo trovato un elemento con campo nome uguale a name allora: 
	if (!ListIsEmpty(tmp)) {
		// se l'elemento da eliminare si trova in testa
		if (prev == NULL) {
			Item* tmp_2 = i; 
			i = ListGetTail(i); 
			ElemDelete(&tmp_2->value); 
			free(tmp_2);
		}
		else {	// prev != NULL, dunque l'elemento da togliere non si trova nella testa 
			prev->next = tmp->next; 
			ElemDelete(&tmp->value); 
			free(tmp); 
		}
	}
	return i; 
}