#include "minheap.h"

static bool IsHeapRec(const Heap* h, int i) {
	
	if (i >= (int)h->size) {
		return true; 
	}

	int l = HeapLeft(i); 
	int r = HeapRight(i); 

	if (l < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, l)) > 0) {
		return false; 
	}
	if (r < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, r)) > 0) {
		return false; 
	}

	return IsHeapRec(h, l) && IsHeapRec(h, r); 
}

bool IsHeap(const Heap* h) {
	if (h == NULL) {
		return false; 
	}
	if (h->size == 0) {
		return true; 
	}

	return IsHeapRec(h, 0);
}