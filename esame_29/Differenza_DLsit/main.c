#include <stdlib.h>

#include "diff_dlist.h"

Item* ListCreateFromVector(ElemType* arr, size_t size) {
	Item* i = DListCreateEmpty(); 
	for (size_t j = 0; j < size; ++j) {
		i = DListInsertBack(i, arr + j);
	}
	return i;
}

int main(void) {
	ElemType arr1[] = { 1, 0, 0, 0 };
	ElemType arr2[] = { 4, 9, 9 }; 
	size_t size_1 = sizeof(arr1) / sizeof(arr1[0]);
	size_t size_2 = sizeof(arr2) / sizeof(arr2[0]);

	Item* l1 = ListCreateFromVector(arr1, size_1); 
	Item* l2 = ListCreateFromVector(arr2, size_2);

	printf("sottrazione: \n"); 
	DListWriteStdout(l1); 
	DListWriteStdout(l2); 

	printf("\nrisultato:\n");
	Item* res = DListDiff(l1, l2); 
	DListWriteStdout(res); 

	DListDelete(l1); 
	DListDelete(l2);
	DListDelete(res); 

	return 0; 
}