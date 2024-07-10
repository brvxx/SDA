#include <stdlib.h> 

#include "no_cycle.h"

void RemoveCycle(Item* i) {
	Item** adress = NULL; 
	size_t list_size = 0; 
	bool done = false; 

	while (!ListIsEmpty(i)) {
		list_size++;
		adress = realloc(adress, list_size * sizeof(Item*)); 
		adress[list_size - 1] = i; 

		for (size_t j = 0; j < list_size; ++j) {
			if (adress[j] == i->next) {
				i->next = NULL; 
				done = true; 
				break; 
			}
		}
		if (done) {	
			break; 
		}
		i = ListGetTail(i); 
	}

	free(adress); 
}