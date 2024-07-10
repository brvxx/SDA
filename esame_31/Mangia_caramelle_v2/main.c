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

	int res = MangiaCaramelle(h, 4); 

	printf("caramelle rimanenti: %d", res); 

	HeapDelete(h);

	return 0;
}