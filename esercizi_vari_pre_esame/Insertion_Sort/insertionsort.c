#include <stdlib.h>

void InsertionSort(int* v, size_t v_size) {

	// ciclo parte da 1 perché consideriamo il primo elemento già in ordine
	for (int i = 1; i < (int)v_size; ++i) {
		int j = i;
		int tmp = v[i];
		while (j > 0 && v[j - 1] > tmp) {
			v[j] = v[j - 1]; // shifto a dx l'elemento maggiore di tmp
			--j; // ora j è l'indice dell'ex posizione dell'elemento shiftato --> ora libera 
		}
		v[j] = tmp;
	}
}