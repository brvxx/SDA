#include "tree.h"

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 0,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					TreeCreateRoot(arr + 3,
						TreeCreateRoot(arr + 7, NULL, NULL),
						TreeCreateRoot(arr + 5, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	TreeDelete(t1);

	return 0;
}

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

#include "list.h"

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}