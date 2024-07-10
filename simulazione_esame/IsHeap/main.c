#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "minheap.h"

extern bool IsHeap(const Heap* h);

int main(void) {

	ElemType arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Heap* h = HeapCreateEmpty(); 
	h->size = size; 
	h->data = malloc(h->size * sizeof(ElemType)); 
	
	memcpy(h->data, arr, h->size * sizeof(ElemType)); 

	bool res = IsHeap(h); 

	res ? printf("la heap passata alla IsHeap era una minheap\n\n") : printf("la heap passata alla IsHeap non era una minheap\n\n"); 

	HeapDelete(h); 

	return 0; 
}