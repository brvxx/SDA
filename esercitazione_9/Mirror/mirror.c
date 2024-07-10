#include "tree.h"

static bool TreeIsMirrorRec(const Node* l, const Node* r) {

	if (TreeIsEmpty(l) && TreeIsEmpty(r)) {
		return true; 
	}

	if ((TreeIsEmpty(l) || TreeIsEmpty(r)) ||
			ElemCompare(TreeGetRootValue(l), TreeGetRootValue(r)) != 0) {
		return false; 
	}
	
	return TreeIsMirrorRec(TreeLeft(l), TreeRight(r)) && TreeIsMirrorRec(TreeRight(l), TreeLeft(r));
}

bool TreeIsMirror(const Node* t) {		
	
	// TreeLeft e TreeRight funzionano anche se il node
	// passato per parametro è null
	Node* l = TreeLeft(t);
	Node* r = TreeRight(t); 
	
	return TreeIsMirrorRec(l, r); 
}