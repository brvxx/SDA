// Questo algoritmo è chaiamato Cocktail shaker sort, è un miglioramento del bubble sort 
// perchè agisce esattamente come il bubble solo che all'interno dello stesso "giro" di
// while oltre a spostare l'elemento maggiore a destra, viene pure spostato quello minore
// a sinistra, così da velocizzare il processo.


#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void BubbleSort(int* v, int dim) {
	
	int sorted = 0;			// è una flag che ci permette di dire se al termine della passata di controlli tra le coppie il vettore sia già ordinato, così da non	
							// andare avanti inutilmente con altri controlli --> questo accade ovviamente se non sono avvenute delle swap
	for(int i = 0; dim > 1; ++i) {
		
		sorted = 1; 
		
		for (int j = i; j < dim - 1; ++j) {  // ovviamente il ciclo andrà avanti finchè j < dim - 1 e non dim, perchè se no andrebbe a leggere fuori dalla memoria guardando il v[j + 1]
			if (v[j] > v[j + 1]) {
				swap(v + j, v + j + 1);
				sorted = 0; 
			}
		}
		for (int k = dim - 1; k > 0; --k) {	
			if (v[k] < v[k - 1]) {
				swap(v + k, v + k - 1);
				sorted = 0;
			}
		}
		
		if (sorted) {
			break; 
		}

		dim--;
	}
}

int main(void) {

	int vec[] = { 100, 90, 45, 33 , 23, 7, 2, 1 };
	int dim = 8;

	BubbleSort(vec, dim);

	for (int i = 0; i < dim; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}