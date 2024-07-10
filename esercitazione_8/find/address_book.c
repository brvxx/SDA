#include "list.h"

const ElemType* Find(const Item* i, const char* name) {
	while (!ListIsEmpty(i)) {
		if (strcmp(i->value.name, name) == 0) {
			break; 
		}
		i = ListGetTail(i); 
	}
	if (i) {
		return ListGetHeadValue(i);
	}
	return NULL; 
}