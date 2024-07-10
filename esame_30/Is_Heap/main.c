#include <stdio.h>

#include "minheap.h"

extern bool IsHeap(const Heap* h);

int main(void) {

	ElemType arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Heap* h = HeapCreateEmpty(); 
	h->data = arr; 
	h->size = size; 

	bool res = IsHeap(h); 

	res ? printf("il vettore res e' una min-heap") : printf("il vettore res e' una min-heap");

	return 0; 
}

