#include "no_cycle.h"

extern void RemoveCycle(Item* i);

Item* ListGetLast(Item* i) {
	while (!ListIsEmpty(ListGetTail(i))) {
		i = ListGetTail(i);
	}
	return i; 
}

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	Item* tmp = ListGetTail(l1);
	Item* tmp1 = ListGetLast(l1); 
	tmp1->next = tmp; 

	RemoveCycle(l1); 

	ListWriteStdout(l1); 


	ListDelete(l1);

	return 0;
}