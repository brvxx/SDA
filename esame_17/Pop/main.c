#include "minheap.h"

extern bool Pop(Heap* h, ElemType* e);

int main(void) {

	ElemType arr[] = { 9, 1, 4, 10, 5, 2, 3, 7, 8 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		HeapMinInsertNode(h, arr + i);
	}
	HeapWriteStdout(h);

	ElemType popped = 0; 
	bool res = Pop(h, &popped); 

	if (res) {
		printf("\nil primo elemento della min-heap e' stato poppato correttamente e il suo valore e': %d\n\n", popped);
	}
	else {
		printf("\nnon e' stato possibile poppare il primo elemento del min-heap in quanto era vuota\n\n"); 
	}

	HeapWriteStdout(h);

	HeapDelete(h);

	return 0;
}