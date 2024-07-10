#include "tree.h"

void SuccessoreRec(const Node* t, const Node* n, const Node** max_n) {
	if (TreeIsEmpty(t)) {
		return; 
	}

	if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(n)) > 0 &&
			(TreeIsEmpty(*max_n) || ElemCompare(TreeGetRootValue(t), TreeGetRootValue(*max_n)) < 0)) {
	
		*max_n = t; 
	}

	SuccessoreRec(TreeLeft(t), n, max_n);
	SuccessoreRec(TreeRight(t), n, max_n);
}

const Node* Successore(const Node* t, const Node* n) {
	const Node *max = TreeCreateEmpty(); 
	SuccessoreRec(t, n, &max); 

	return max; 
}