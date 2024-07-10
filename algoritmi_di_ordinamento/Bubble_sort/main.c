// questo algoritmo � sostanzialmente un upgrade del selection sort, infatti questo algoritmo 
// � in grado di riconoscere quando una sequenza � gi� ordinata per potersi fermare mentre 
// il selection sort va avanti fino alla fine dei due cicli. Sostanzialmente il suo modello 
// operativo consiste nel confrontare tra loro le coppie di valori adiacenti spostando a 
// destra quello di valore maggiore, cos� che andando avnati verr� portato l'elemento di 
// valore maggiore in ultima posizione del vettore, cos� da poter reiterare il processo 
// sugli n - 1 elementi rimannenti.

#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void BubbleSort(int* v, int dim) {
	
	int sorted = 0;			// � una flag che ci permette di dire se al termine della passata di controlli tra le coppie il vettore sia gi� ordinato, cos� da non	
							// andare avanti inutilmente con altri controlli --> questo accade ovviamente se non sono avvenute delle swap
	while (dim > 1 && !sorted) {
		sorted = 1; 
		for (int i = 0; i < dim - 1; ++i) {  // ovviamente il ciclo andr� avanti finch� i < dim - 1 e non dim, perch� se no andrebbe a leggere fuori dalla memoria guardando il v[i + i]
			if (v[i] > v[i + 1]) {
				swap(v + i, v + i + 1);
				sorted = 0; 
			}
		}
		dim--;
	}
}

int main(void) {

	int vec[] = { 41, 11, 3, 2 , 11, 44, 100, 23 };
	int dim = 8;

	BubbleSort(vec, dim);

	for (int i = 0; i < dim; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}