#include "minheap.h"

extern size_t ConnectRopes(Heap* ropes);

int main(void) {

	ElemType arr[] = { 1, 3, 4, 6, 4 };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Heap* h = HeapCreateEmpty(); 

	for (size_t i = 0; i < size; ++i) {
		HeapMinInsertNode(h, arr + i); 
	}

	HeapWriteStdout(h); 

	size_t res = ConnectRopes(h); 

	printf("costo totale: %zu", res); 

	HeapDelete(h);

	return 0; 
}