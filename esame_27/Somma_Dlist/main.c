#include <stdlib.h>

#include "sum_dlist.h"

extern Item* DListSum(const Item* i1, const Item* i2);

Item* ListCreateFromVector(ElemType* arr, size_t size) {
	Item* i = DListCreateEmpty();
	for (size_t j = 0; j < size; ++j) {
		i = DListInsertBack(i, arr + j);
	}
	return i;
}

int main(void) {
	ElemType arr1[] = { 9, 5, 4 };
	ElemType arr2[] = { 6, 9 };
	size_t size_1 = sizeof(arr1) / sizeof(arr1[0]);
	size_t size_2 = sizeof(arr2) / sizeof(arr2[0]);

	Item* l1 = ListCreateFromVector(arr1, size_1);
	Item* l2 = ListCreateFromVector(arr2, size_2);

	printf("somma: \n");
	DListWriteStdout(l1);
	DListWriteStdout(l2);

	printf("\nrisultato:\n");
	Item* res = DListSum(l1, l2);
	DListWriteStdout(res);

	DListDelete(l1);
	DListDelete(l2);
	DListDelete(res);

	return 0;
}