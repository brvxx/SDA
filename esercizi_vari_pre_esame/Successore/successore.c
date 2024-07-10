#include "tree.h"


static void SuccessoreRec(const Node* t, const Node* n, const Node** succ, int target) {
	if (TreeIsEmpty(t)) {
		return; 
	}

	if (t->value > target &&
			(TreeIsEmpty(*succ) || ElemCompare(TreeGetRootValue(t), TreeGetRootValue(*succ)) < 0)) {
		*succ = t; 
	}

	SuccessoreRec(TreeLeft(t), n, succ, target); 
	SuccessoreRec(TreeRight(t), n, succ, target);
}

const Node* Successore(const Node* t, const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL; 
	}
	int target = n->value;
	const Node* res = TreeCreateEmpty(); 

	SuccessoreRec(t, n, &res, target); 

	return res; 
}