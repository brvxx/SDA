#include "list.h"

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL; 
	}
	
	Item* res = ListCreateEmpty(); 
	ElemType tmp; 
	
	while (ElemRead(f, &tmp) == 1) {
		res = ListInsertHead(&tmp, res);
	}

	fclose(f);
	return res; 
}