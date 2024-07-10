#include "doublelist.h"

extern Item* ConcatenaN(Item** v, size_t v_size);

int main(void) {

	ElemType arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	ElemType arr2[] = { 10, 11, 12, 13, 14, 15 }; 

	size_t size1 = sizeof(arr1) / sizeof(arr1[0]); 
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]); 

	Item* l1 = DListCreateEmpty(); 
	Item* l2 = DListCreateEmpty(); 

	for (size_t i = 0; i < size1; i++) {
		l1 = DListInsertBack(l1, arr1 + i); 
	}
	for (size_t i = 0; i < size2; i++) {
		l2 = DListInsertBack(l2, arr2 + i); 
	}

	DListWriteStdout(l1); 
	DListWriteStdout(l2);

	Item* vec[] = { NULL, l1, NULL, NULL, l2, NULL }; 
	size_t vec_size = sizeof(vec) / sizeof(vec[0]); 

	Item* res = ConcatenaN(vec, vec_size); 

	DListWriteStdout(res); 

	DListDelete(res); 

	return 0; 
}