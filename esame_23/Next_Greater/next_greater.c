#include <stdlib.h>
#include <limits.h>

#include "next_greater.h"

static int ListGetLen(const Item* i) {
	int res = 0; 
	
	while (!ListIsEmpty(i)) {
		i = ListGetTail(i); 
		++res; 
	}
	return res; 
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {
	int len = ListGetLen(list); 
	*answer_size = (size_t)len; 

	if (len == 0) {
		return NULL; 
	}

	int* res = calloc(len, sizeof(int)); 

	for (int i = 0; i < len; ++i) {
		Item* tmp = list->next; 
		while (!ListIsEmpty(tmp)) {
			if (list->value < tmp->value) {
				res[i] = tmp->value; 
				break; 
			}
			tmp = ListGetTail(tmp); 
		}
		if (tmp == NULL) {
			res[i] = INT_MIN;
		}
		list = ListGetTail(list); 
	}

	return res; 
}