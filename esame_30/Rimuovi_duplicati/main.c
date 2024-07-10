#include <stdlib.h>

#include "no_dups.h"

Item* CreateListFromVector(const ElemType* v, size_t size) {
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	return list;
}

int main(void) {

	ElemType arr[] = { 12, 3, 4, 3, 5, 5, 7 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* list = CreateListFromVector(arr, size);
	ListWriteStdout(list);

	Item* new_list = RemoveDuplicates(list);
	printf("\nla nuova lista privata di doppioni sara': \n\n");
	ListWriteStdout(new_list);

	return 0;
}