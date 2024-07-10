#include "minheap.h"

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

int main(void) {

	ElemType arr[] = { 9, 1, 4, 10, 0, 2, 3, 7, 8 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Heap* h1 = HeapCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		HeapMinInsertNode(h1, arr + i);
	}
	HeapWriteStdout(h1);

	ElemType arr1[] = { 12, 1, 3, 4, 5, 99 };
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	Heap* h2 = HeapCreateEmpty();
	for (size_t i = 0; i < size1; ++i) {
		HeapMinInsertNode(h2, arr1 + i);
	}
	HeapWriteStdout(h2);

	Heap* res = MergeHeap(h1, h2);

	HeapWriteStdout(res); 

	HeapDelete(res); 
	HeapDelete(h2); 
	HeapDelete(h1);
	return 0;
}