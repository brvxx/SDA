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

    ElemType popped = 0; 
    for (int i = 0; i < k; ++i) {
        Pop(h, &popped); 
        popped -= popped - (int)sqrt((double)popped);
        HeapMaxInsertNode(h, &popped); 
    }

    int sum = 0; 
    for (size_t j = 0; j < h->size; ++j) {
        sum += h->data[j]; 
    }
    return sum; 
}