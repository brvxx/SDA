#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {
	ElemType arr[] = { 2, 3, 5, 6, 1, 9, 7, 10 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Heap* res = HeapMinHeapify(arr, size);

	HeapWriteStdout(res);
	HeapDelete(res);

	return 0; 
}