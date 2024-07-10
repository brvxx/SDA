#include <stdbool.h>

#include "tree.h"

static void PercorsoSommaRec(Node* t, const ElemType* target, int sum_curr, bool* test) {
	if (TreeIsEmpty(t)) {
		if (sum_curr == *target) {
			*test = true;
		}
		return; 
	}
	if (sum_curr > *target) {
		return; 
	}

	PercorsoSommaRec(TreeLeft(t), target, sum_curr + t->value, test); 
	PercorsoSommaRec(TreeRight(t), target, sum_curr + t->value, test); 
}

bool PercorsoSomma(Node* t, const ElemType* target) {
	bool test = false; 
	if (TreeIsEmpty(t)) {
		return test; 
	}

	PercorsoSommaRec(t, target, 0, &test); 

	return test; 
}