#include "minheap.h"

extern void HeapMinMoveDownRec(Heap* h, int i) {
	if (i >= (int)h->size) {
		return; 
	}

	int l = HeapLeft(i);
	int r = HeapRight(i);
	int smallest = i; 

	if (l < (int)h->size && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, smallest)) < 0) {
		smallest = l; 
	}
	if (r < (int)h->size && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, smallest)) < 0) {
		smallest = r; 
	}
	if (smallest != i) {
		ElemSwap(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, i)); 
		HeapMinMoveDownRec(h, smallest);
	}
	else {
		return;
	}
}