#include "reverse.h"

int ListGetLen(const Item* i) {
	int res = 0; 
	while (!ListIsEmpty(i)) {
		++res;
		i = ListGetTail(i);
	}
	return res; 
}

Item* ListReverse(Item* i) {
	Item* prev = NULL; 
	Item* curr = i; 
	Item* next = curr->next; 

	while (!ListIsEmpty(curr)) {
		curr->next = prev; 
		prev = curr; 
		curr = next; 

		if (curr) {
			next = curr->next; 
		}
	}

	return prev; 
}

Item* Reverse(Item* list, int left) {
	if (left <= 0) {
		return ListReverse(list);
	}
	if (left >= ListGetLen(list) - 1) {
		return list; 
	}

	Item* tmp = list; 
	for (int i = 0; i < left - 1; ++i) {
		tmp = ListGetTail(tmp); 
	}
	tmp->next = ListReverse(tmp->next); 

	return list; 
}