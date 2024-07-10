#include <stdlib.h>
#include <stdio.h>

#include "stacks.h"


int main(void) {
	
	Stack vec[] = {
		{.m = 5, .elements = (unsigned[]) {1, 1, 1, 2, 3}},
		{.m = 3, .elements = (unsigned[]) {2, 3, 4}},
		{.m = 4, .elements = (unsigned[]) {1, 4, 5, 2}}
	}; 
	size_t size = sizeof(vec) / sizeof(vec[0]); 
	
	unsigned value = MaxSumNStack(vec, size); 

	printf("Valore di ogni pila stack: %d \n\nElenco degli stack aggiornati: \n", value); 
	if (value == 0) {
		for (size_t i = 0; i < size; ++i) {
			printf("%zu) []\n", i + 1);
		}
	}
	else {
		for (size_t i = 0; i < size; ++i) {
			printf("%zu) [", i + 1);
			for (size_t j = 0; j < vec[i].m; ++j) {
				printf("%d", vec[i].elements[j]);
				if (j != vec[i].m - 1) {
					printf(", ");
				}
			}
			printf("]\n"); 
		}
	}

	return 0; 
}