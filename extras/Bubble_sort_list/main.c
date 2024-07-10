#include "list.h"

extern Item* ListBubbleSort(Item* i); 

int main(void) {

	ElemType arr[] = { 1, 3, 7, 2, 3, 4, 5 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	l1 = ListBubbleSort(l1); 

	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}