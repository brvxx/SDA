#include "no_dups.h"

Item* RemoveDuplicates(const Item* i) {

	Item* res = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		Item* tmp = res;
		const ElemType* head = ListGetHeadValue(i);

		while (!ListIsEmpty(tmp)) {
			if (ElemCompare(head, ListGetHeadValue(tmp)) == 0) {
				break;
			}
			tmp = ListGetTail(tmp);
		}

		if (ListIsEmpty(tmp)) {
			res = ListInsertBack(res, head);
		}
		i = ListGetTail(i);
	}
	return res;
}