// questo algoritmo ha un principio di funzionamento molto semplice; si tratta di cercare 
// all'interno della sequenza il valore maggiore confrontando tra loro tutti gli elementi
// e mettendolo in fondo alla sequenza e successivamente ripetere il processo n - 2 volte 
// diminuendo virtualmente la dimensione del vettore di uno, infatti l'ultimo elemento
// sar� di volta in volta gi� ordinato. 
//
// nota che il processo di confronto avviene n - 1 volte in totale, perch� quando arrivo 
// ad avere che la dimensione virtuale del vettore � uno non sto a fare nessun confronto 
// perch� una sequenza lunga 1 � gi� ordinata di per s�.



#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp;
}

int FindMax(int* v, int n) {
	int pos = 0;					// ipotizziamo per partire che il valore massimo si trovi nella posizione 0 (la prima) 
	for (int i = 1; i < n; ++i) {
		if (v[i] > v[pos]) {
			pos = i;
		}
	}
	return pos; 
}

void SelectionSort(int* v, int dim) {
	int max;		// sar� l'indice del elemento con valore maggiore, viene inizializzato grazie alla funzione che trova proprio la posizione di questo valore 
	
	while (dim > 1) {	// ovviamente se dim = 1, dovremmo andare ad ordinare un vettore lungo 1, ma questo � gi� ordinato per forza 
		max = FindMax(v, dim); 
		if (max < dim - 1) {	// per evitare di fare swap inutili se l'elemento di valore massimo � gi� in ultima posizione 
			swap(v + max, v + (dim - 1));
		}
		dim--; 
	}
}

int main(void) {

	int vec[] = { 41, 11, 3, 2 , 11, 44, 100, 23 };
	int dim = 8; 

	SelectionSort(vec, dim);

	for (int i = 0; i < dim; ++i) {
		printf("%d ", vec[i]);
	}

	return 0; 
}