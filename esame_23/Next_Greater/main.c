#include "list.h"

extern ElemType* NextGreater(const Item* list, size_t* answer_size);

int main(void) {

	ElemType arr[] = { 2, 3, 1, 4, 7, 2 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	size_t size_vec = 0; 
	ElemType* vec = NextGreater(l1, &size_vec); 

	printf("lunghezza del vettore: %zu\n\n", size_vec); 
	for (size_t i = 0; i < size_vec; ++i) {
		printf("%d ", vec[i]); 
	}

	ListDelete(l1);

	return 0;
}