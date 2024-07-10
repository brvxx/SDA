#include "list.h"

extern Item* PariDispari(Item* i);

int main(void) {

	ElemType arr[] = { 1, 3, 4, 7, 8, -2 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	l1 = PariDispari(l1); 

	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}