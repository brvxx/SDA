#include "differenza.h"

extern Item* Differenza(const Item* i1, const Item* i2);

int main(void) {

	ElemType arr1[] = { '7', '1', '0', '1'};
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size1; ++i) {
		l1 = ListInsertBack(l1, arr1 + i);
	}

	ElemType arr2[] = { '3', '2', '4'};
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

	Item* l2 = ListCreateEmpty();

	for (size_t i = 0; i < size2; ++i) {
		l2 = ListInsertBack(l2, arr2 + i);
	}

	ListWriteStdout(l1);
	ListWriteStdout(l2);

	Item* res = Differenza(l1, l2); 
	ListWriteStdout(res);

	ListDelete(l1);
	ListDelete(l2);
	ListDelete(res);

	return 0;
}