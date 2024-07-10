#include "maxheap.h"

extern int MangiaCaramelle(Heap* h, int k);

int main(void) {

	ElemType arr[] = { 1, 1, 1, 1 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Heap* h = HeapCreateEmpty(); 
	for (size_t i = 0; i < size; ++i) {
		HeapMaxInsertNode(h, arr + i);
	}
	HeapWriteStdout(h); 
	int seconds = 4;
	int res = MangiaCaramelle(h, seconds); 

	printf("\nil numero rimasto di caramelle dopo la scorpacciata e': %d\n", res);

	return 0; 
}