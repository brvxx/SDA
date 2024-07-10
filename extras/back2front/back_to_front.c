#include "list.h"

static int ListGetLen(Item* i) {
	int res = 0; 
	while (!ListIsEmpty(i)) {
		++res; 
		i = ListGetTail(i);
	}
	return res; 
}

void BackToFront(Item** i) {
	int len = ListGetLen(*i); 
	if (len == 0 || len == 1) {
		return; 
	}
	
	Item* prev = *i; 
	Item* curr = prev->next; 

	while (!ListIsEmpty(curr->next)) {
		prev = curr; 
		curr = curr->next; 
	}
	prev->next = NULL; 
	curr->next = *i; 
	*i = curr; 
}