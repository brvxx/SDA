#include <stdlib.h>
#include <string.h>

#include "maxheap.h"

extern int LastStoneWeight(Heap* h);

int main(void) {
	ElemType arr[] = { 77, 21, 18 };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Heap* h = HeapCreateEmpty(); 
	h->size = size; 
	h->data = malloc(h->size * sizeof(ElemType)); 

	memcpy(h->data, arr, size * sizeof(ElemType)); 

	int last = LastStoneWeight(h); 

	printf("il valore dell'ultima pietra rimasta e': %d", last); 

	return 0; 

}