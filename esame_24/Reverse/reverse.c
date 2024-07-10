#include "reverse.h"	

Item* Reverse_links(Item* list) {
	Item* prev = NULL; 
	Item* curr = list;

	while (!ListIsEmpty(curr)) {
		Item* next = curr->next;
		
		curr->next = prev; 

		prev = curr; 
		curr = next; 
	}

	return prev; 
}

int ListGetLen(Item* i) {
	int res = 0; 

	while (!ListIsEmpty(i)) {
		++res;
		i = ListGetTail(i); 
	}
	return res; 
}

Item* Reverse(Item* list, int right) {
	int len = ListGetLen(list); 

	if (right <= 1) {
		return list; 
	}
	if (right >= len) {
		return Reverse_links(list); 
	}

	Item* end = list; 
	for (int i = 1; i < right; ++i) {
		end = ListGetTail(end); 
	}
	Item* tmp = end->next; 
	// stacchiamo la lista da invertire dalla restante parte
	end->next = NULL; 

	// end ora sarà un puntatore alla testa della lista
	end = Reverse_links(list); 

	// la vecchia testa della lista ora sarà l'elemento che precede tmp 
	list->next = tmp; 

	return end; 
}