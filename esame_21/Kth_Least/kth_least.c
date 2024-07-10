#include <stdlib.h>
#include <string.h>

#include "minheap.h"

int KthLeast(const int* v, size_t n, int k) {
	
	// costo in memoria O(n) --> allochiamo memoria pari alla dimensione dell'input
	int* tmp = malloc(n * sizeof(int)); 
	memcpy(tmp, v, n * sizeof(int)); 


	Heap* h = HeapCreateEmpty();
	h->size = n; 
	h->data = tmp; 

	//heapify --> costo O(n) 
	for (int i = HeapParent((int)h->size - 1); i >= 0; --i) {
		HeapMinMoveDown(h, i); 
	}

	int res = 0; 

	// complessità di questo processo sarà k * log2n --> nel caso peggiore, ossia quando k = n 
	// la complessità sarà O(n*logn) 
	while (k > 0) {
		res = h->data[0]; 
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size--; 

		HeapMinMoveDown(h, 0); 

		--k; 
	}

	h->size = n; 
	HeapDelete(h); 
	return res; 
}
// note: se non avessi sfruttato le proprietà della heap e avessi cercato ogni volta il minimo all'interno 
// di un vettore lungo nel caso peggiore la complessità dell'algoritmo sarebbe stata O(n^2), poiché la ricerca
// del minimo in un vettore ha costo O(n) mentre per le heap ha costo O(1), poi la riorganizzazione della heap 
// costa O(logn), ossia il costo della movedown dell'elemento swappato. 