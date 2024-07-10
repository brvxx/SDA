#include "elemtype.h"
#include "list.h"

Item* Intersect(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	const Item* tmp; 
	const ElemType* head; 
	
	while (!ListIsEmpty(i1)) {
		tmp = i2; 
		head = ListGetHeadValue(i1); 
		
		while (!ListIsEmpty(tmp)) {
			if (ElemCompare(head, ListGetHeadValue(tmp)) == 0) {
				break; 
			}
			tmp = ListGetTail(tmp); 
		}

		if (tmp) {
			res = ListInsertBack(res, head);
		}

		i1 = ListGetTail(i1);
	}

	return res; 
}