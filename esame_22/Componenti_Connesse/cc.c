#include "cc.h"

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	int connesse = 0; 
	bool in = false;
	
	while (!ListIsEmpty(i)) {
		ElemType tmp = i->value; 
		bool found = false; 

		for (size_t j = 0; j < v_size; ++j) {
			if (v[j] == tmp) {
				found = true; 
				in = true; 
				break;
			}
		}

		if (in == true && found == false) { 
			connesse++;
			in = false; 
		}

		i = ListGetTail(i); 
	}
	if (in == true) {
		connesse++; 
	}
	return connesse; 
}