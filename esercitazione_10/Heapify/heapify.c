#include <stdlib.h>
#include <string.h>

#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	Heap* res = HeapCreateEmpty(); 
	res->size = v_size; 
	res->data = malloc(res->size * sizeof(ElemType)); 

	memcpy(res->data, v, res->size * sizeof(ElemType));

	// oppure fai i = HeapParent((int)h->size - 1) 
	for (int i = (int)(res->size / 2 - 1); i >= 0; --i) {
		HeapMinMoveDown(res, i);
	}

	return res; 
}