#include "cc.h"

extern int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size);

int main(void) {

	ElemType arr[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Item* l1 = ListCreateEmpty(); 
	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i); 
	}

	ElemType v[] = { 7, 8, 0, 4, 6 }; 
	size_t v_size = sizeof(v) / sizeof(v[0]); 

	int res = ComponentiConnesse(l1, v, v_size); 

	printf("componenti connesse: %d", res); 

	ListDelete(l1); 

	return 0; 
}