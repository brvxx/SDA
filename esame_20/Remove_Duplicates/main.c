#include "remove.h"

int main(void) {

	ElemType arr[] = { 1, 1, 1, 2, 2, 3, 4, 5, 5 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	Item* res = RemoveDuplicates(l1); 
	ListWriteStdout(res);

	ListDelete(res);

	return 0; 
}