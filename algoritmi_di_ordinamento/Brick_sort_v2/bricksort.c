#include <stdlib.h>
#include <stdbool.h>

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BrickSort(int* v, size_t v_size) {
	bool done = false;

	while (!done) {
		done = true;

		// scambio elementi coppie con indice dispari
		for (int i = 1; i < (int)v_size; i = i + 2) {
			if ((i + 1) < (int)v_size && v[i] > v[i + 1]) {
				swap(v + i, v + i + 1); 
				done = false; 
			}
		}

		// scambio elementi coppie con indice pari
		for (int i = 0; i < (int)v_size; i = i + 2) {
			if ((i + 1) < (int)v_size && v[i] > v[i + 1]) {
				swap(v + i, v + i + 1);
				done = false; 
			}
		}
	}
}
// nota che NON SI PUO' diminuire la size come si fa nel bubble sort, infatti non è detto che 
// al termine del primo giro del for in ultima posizione ci sia l'elemento maggiore --> prova 
// con vettore { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }