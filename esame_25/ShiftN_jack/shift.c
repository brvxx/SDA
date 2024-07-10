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

	// item fittizio che punta alla testa della lista
	Item fake_head = { .next = list }; 
	Item* curr = list; 
	Item* prev = &fake_head;
	for (size_t i = 0; i < n; ++i) {
		Item* fol = curr->next; 
		Item* folfol = fol->next; 

		prev->next = fol; 
		fol->next = curr; 
		curr->next = folfol;

		prev = fol; 
	}

	return fake_head.next;
}