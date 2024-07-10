#include "minheap.h"

void HeapMinHeapsort(Heap* h) {
	size_t size = h->size; // ci ricordiamo della dimensione iniziale della heap

	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size--; 
		HeapMinMoveDown(h, 0); 
	}

	h->size = size;
}
// nota che al termine dell'esecuizione "l'heap" che ritorniamo sarà ancora un heap ma non
// più min-heap bensì max-heap. 