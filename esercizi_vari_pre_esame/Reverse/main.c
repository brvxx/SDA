#include "list.h"

extern Item* Reverse(Item* list, int left);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	l1 = Reverse(l1, 3);
	
	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}