#include "minheap.h"

int main(void) {

	ElemType arr[] = { 9, 1, 4, 10, 0, 2, 3, 7, 8 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		HeapMinInsertNode(h, arr + i);
	}
	HeapWriteStdout(h);

	HeapDelete(h);

	return 0;
}