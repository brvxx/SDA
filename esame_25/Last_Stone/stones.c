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

int LastStoneWeight(Heap* h) {
    while (h->size > 1) {
        int stone1 = 0; 
        int stone2 = 0; 

        Pop(h, &stone1); 
        Pop(h, &stone2); 

        if (stone1 != stone2) {
            stone1 -= stone2; 
            HeapMaxInsertNode(h, &stone1); 
        }
    }
    if (h->size == 0) {
        return 0; 
    }
    else {
        return h->data[0];
    }
}