#include "elemtype.h"
#include "list.h"

Item* IntersectNoRep(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	const Item* tmp1;
	const Item* tmp2; 
	const ElemType* head;

	while (!ListIsEmpty(i1)) {
		tmp1 = i2;
		head = ListGetHeadValue(i1);

		while (!ListIsEmpty(tmp1)) {
			if (ElemCompare(head, ListGetHeadValue(tmp1)) == 0) {
				break;
			}
			tmp1 = ListGetTail(tmp1);
		}

		if (tmp1) {
			tmp2 = res;
			while (!ListIsEmpty(tmp2)) {
				if (ElemCompare(ListGetHeadValue(tmp2), head) == 0) {
					break;
				}
				tmp2 = ListGetTail(tmp2);
			}
			if (!tmp2) {
				res = ListInsertBack(res, head);
			}
		}

		i1 = ListGetTail(i1);
	}

	return res;

}

Item* DiffNoRep(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	const Item* tmp1;
	const Item* tmp2;
	const ElemType* head;

	while (!ListIsEmpty(i1)) {
		tmp1 = i2;
		head = ListGetHeadValue(i1);

		while (!ListIsEmpty(tmp1)) {
			if (ElemCompare(head, ListGetHeadValue(tmp1)) == 0) {
				break;
			}
			tmp1 = ListGetTail(tmp1);
		}
		if (!tmp1) {
			tmp2 = res; 
			while (!ListIsEmpty(tmp2)) {
				if (ElemCompare(ListGetHeadValue(tmp2), head) == 0) {
					break;
				}
				tmp2 = ListGetTail(tmp2);
			}
			if (!tmp2) {
				res = ListInsertBack(res, head);
			}
		}

		i1 = ListGetTail(i1);
	}

	return res;
}