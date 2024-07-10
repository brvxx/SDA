#include "list.h"

int ListGetLen(const Item* i) {
	int res = 0; 
	while (!ListIsEmpty(i)) {
		res++;
		i = ListGetTail(i); 
	}
	return res; 
}

const Item* CommonTail(const Item* i1, const Item* i2) {
	int len1 = ListGetLen(i1); 
	int len2 = ListGetLen(i2); 
	int offset = 0; 

	if (len1 == 0 || len2 == 0) {
		return NULL; 
	}
	
	// facciamo partire le liste dallo stesso punto 
	if (len1 > len2) {
		offset = len1 - len2; 
		for (int i = 0; i < offset; ++i) {
			i1 = ListGetTail(i1); 
		}
	}
	if (len1 < len2) {
		offset = len2 - len1;
		for (int i = 0; i < offset; ++i) {
			i2 = ListGetTail(i2);
		}
	}

	const Item* common_tail = NULL; 
	while (!ListIsEmpty(i1)) {
		if (i1 == i2) {
			common_tail = i1; 
			break; 
		}
		i1 = ListGetTail(i1);
		i2 = ListGetTail(i2);
	}
	return common_tail;
}