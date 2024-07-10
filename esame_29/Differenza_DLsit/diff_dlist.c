#include <stdbool.h>
#include <stdlib.h>

#include "diff_dlist.h"

const Item* DlistGetLast(const Item* i) {
	while (DListIsEmpty(i)) {
		return NULL; 
	}
	while (!DListIsEmpty(DListGetTail(i))) {
		i = DListGetTail(i); 
	}
	return i; 
}

Item* DlistZeroTrim(Item* i) {
	if (i == NULL) {
		return NULL;
	}
	ElemType zero = 0; 
	bool done = false;

	while (!done) {
		done = true; 
		if (ElemCompare(DListGetHeadValue(i), &zero) == 0 && !DListIsEmpty(DListGetTail(i))) {
			done = false; 
			Item* tmp = i; 
			i = DListGetTail(i);

			ElemDelete(&tmp->value);
			free(tmp); 
		}
	}
	i->prev = NULL;
	return i; 
}

Item* DListDiff(const Item* i1, const Item* i2) {
	Item* res = DListCreateEmpty(); 
	i1 = DlistGetLast(i1); 
	i2 = DlistGetLast(i2); 

	// min = minuendo 
	// sott = sottraendo
	int carry = 0; 
	int min = 0; 
	int sott = 0; 
	int diff = 0; 

	while (!DListIsEmpty(i1)) {
		min = i1->value;
		sott = 0;
		diff = 0;
		if (carry) {
			min -= 1; 
			--carry; 
		}

		if (!DListIsEmpty(i2)) {
			sott += i2->value;
		}
		if (min - sott < 0) {
			// prendo da una qualche cifra successiva
			// come nelle sottrazioni in colonna 
			min += 10; 
			carry++; 
		}
		diff = min - sott; 

		res = DListInsertHead(&diff, res); 

		i1 = DListGetPrev(i1); 
		if (!DListIsEmpty(i2)) {
			i2 = DListGetPrev(i2); 
		}

	}

	return DlistZeroTrim(res); 
}