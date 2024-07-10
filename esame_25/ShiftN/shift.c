#include "shift.h"

size_t ListGetLen(const Item* i) {
	
	size_t res = 0; 
	while (!ListIsEmpty(i)) {
		i = ListGetTail(i); 
		++res; 
	}
	return res; 
}

Item* ShiftN(Item* list, size_t n) {
	size_t len = ListGetLen(list); 
	
	if (len == 0 || len == 1 || n == 0) {
		return list; 
	}

	if (n % (len - 1) == 0) {
		n = len - 1; 
	}
	else {
		n %= len - 1;
	}

	Item* curr = list; 
	Item* new_root = ListGetTail(list);

	for (size_t i = 0; i < n ; ++i) { 
		curr = ListGetTail(curr); 
	}
	list->next = curr->next; 
	curr->next = list; 

	return new_root;
}