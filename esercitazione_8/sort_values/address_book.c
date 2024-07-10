#include "list.h"

Item* Sort(Item* i) {
	if (!i) {
		return NULL; 
	}

	Item* tmp_1 = i;
	Item* tmp_2 = NULL; 
	Item* min_pos = NULL; 

	while (!ListIsEmpty(ListGetTail(tmp_1))) {
		min_pos = tmp_1;
		tmp_2 = ListGetTail(tmp_1); 

		while (!ListIsEmpty(tmp_2)) {
			if (ElemCompare(&min_pos->value, &tmp_2->value) > 0) {
				min_pos = tmp_2; 
			}
			tmp_2 = ListGetTail(tmp_2); 
		}
		if (min_pos != tmp_1) {
			ElemSwap(&min_pos->value, &tmp_1->value);
		}
		tmp_1 = ListGetTail(tmp_1); 
	}

	return i; 

}