#include <stdlib.h>
#include <time.h>

#include "no_cycle.h"

Item* ListCreateFromVector(const ElemType* v, size_t size) {
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	return list;
}

Item* ListCreateLoop(Item* i, int index) {
	Item* loop = NULL;
	Item* tmp = i; 
	for (int j = 0; !ListIsEmpty(ListGetTail(tmp)); ++j) {
		if (j == index) {
			loop = tmp; 
		}
		tmp = ListGetTail(tmp); 
	}
	tmp->next = loop; 
	return i; 
}

int main(void) {
	ElemType arr[] = { 12, 3, 4, 3, 5, 7, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateFromVector(arr, (size_t)size); 

	int min = 0;
	int max = size - 2; 
	// formula per trovare un numero casuale compreso tra min e max
	srand((unsigned)time(NULL)); 
	int index = min + rand() % (max - min + 1);
	l1 = ListCreateLoop(l1, index); 

	RemoveCycle(l1); 
	ListWriteStdout(l1); 

	ListDelete(l1);  
	return 0; 
}