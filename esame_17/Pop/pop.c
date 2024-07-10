#include <stdlib.h>

#include "minheap.h"

bool Pop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h)) {
		return false; 
	}

	*e = ElemCopy(h->data); 
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1)); 
	h->size--; 
	h->data = realloc(h->data, h->size * sizeof(ElemType)); 
	
	HeapMinMoveDown(h, 0);

	return true; 
}