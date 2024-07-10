#include <stdlib.h>
#include <stdbool.h>

#include "no_cycle.h"

void RemoveCycle(Item* i) {
	Item* prev = NULL; 
	Item** vec = NULL; 
	bool loop = false; 

	for (int j = 0; !ListIsEmpty(i); ++j) {

		vec = realloc(vec, (j + 1) * sizeof(Item*));
		vec[j] = i;
	
		for (int k = 0; k < j; ++k) {
			if (vec[k] == vec[j]) {
				loop = true; 
			}
		}
		if (loop) {
			break; 
		}

		prev = i; 
		i = ListGetTail(i); 
	}
	if (i) {
		prev->next = NULL;
	}

	free(vec); 
}