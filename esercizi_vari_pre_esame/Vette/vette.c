#include "list.h"

int ContaVette(const Item* i){
	int vette = 0; 
	while (!ListIsEmpty(i)) {
		const Item* curr = i; 
		const Item* test = curr->next;
		bool vetta = true; 

		while (!ListIsEmpty(test)) {
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(test)) < 0) {
				vetta = false; 
				break; 
			}
			test = ListGetTail(test);
		}
		if (vetta) {
			++vette;
		}
		i = ListGetTail(i);
	}
	return vette; 
}