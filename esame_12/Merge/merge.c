#include "minheap.h"

Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* res = HeapCreateEmpty(); 
	
	if (h1) {	// eseguiamo se e solo se h1 non è NULL, stessa cosa per h2 
		for (size_t i = 0; i < h1->size; ++i) {
			HeapMinInsertNode(res, h1->data + i);
		}
	}
	if (h2) {
		for (size_t i = 0; i < h2->size; ++i) {
			HeapMinInsertNode(res, h2->data + i);
		}
	}
	return res;
}