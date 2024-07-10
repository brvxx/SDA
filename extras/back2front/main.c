#include "list.h"

extern void BackToFront(Item** i); 

int main(void) {

	ElemType arr[] = { 0, 1 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	BackToFront(&l1); 

	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}