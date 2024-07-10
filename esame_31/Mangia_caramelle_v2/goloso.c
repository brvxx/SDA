#include <math.h>
#include <stdlib.h>

#include "maxheap.h"

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

int MangiaCaramelle(Heap* h, int k) {
	if (HeapIsEmpty(h)) {
		return 0; 
	}

	while (k > 0) {
        ElemType popped = 0; 
        Pop(h, &popped); 

        popped = (int)sqrt(popped);
        HeapMaxInsertNode(h, &popped); 
        --k; 
	}
    // calcolo la somma delle caramelle rimanenti
    int sum = 0;
    for (size_t i = 0; i < h->size; ++i) {
        sum += h->data[i];
    }
    return sum; 
}