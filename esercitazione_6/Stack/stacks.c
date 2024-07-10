#include <stdlib.h>
#include <stdbool.h>

#include "stacks.h"

// funzione che controlla se tutti gli stack abbiano lo stesso valore o meno 
bool stacks_compare(unsigned* v, size_t n ) {
	for (size_t i = 1; i < n; ++i) {
		if (v[i] != v[0]) {
			return false; 
		}
	}
	return true; 
}

// funzione che trova ogni volta lo stack dal valore maggiore
int find_max_pos(unsigned* v, size_t n) {
	int max_pos = 0; 
	for (size_t i = 1; i < n; ++i) {
		if (v[i] > v[max_pos]) {
			max_pos = i; 
		}
	}
	return max_pos; 
}

unsigned MaxSumNStack(Stack* stacks, size_t n) {
	unsigned* values = calloc(n, sizeof(unsigned)); 

	// creazione del vettore contenente il valore di ogni stack 
	for (size_t i = 0; i < n; ++i) {
		if (stacks[i].m == 0) {
			free(values);
			return 0; 
		}
		for (size_t j = 0; j < stacks[i].m; ++j) {
			values[i] += stacks[i].elements[j]; 
		}
	}

	int i = 0; 

	// procedimento greedy --> ogni volta dallo stack più appetibile togliamo 
	// l'elemento in cima, finchè tutti gli stack non avranno lo stesso valore
	while (stacks_compare(values, n) == false) {
		i = find_max_pos(values, n); 

		values[i] -= stacks[i].elements[stacks[i].m - 1]; 
		--stacks[i].m; 
	} 
	unsigned res = values[0]; 
	
	free(values);
	return res; 
}