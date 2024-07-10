#include "tree.h"

bool TreeIsMirrorRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true; 
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false; 
	}
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false; 
	}

	return TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) && TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2)); 
}


extern bool TreeIsMirror(const Node* t) {
	Node* t1 = TreeLeft(t); 
	Node* t2 = TreeRight(t); 

	return TreeIsMirrorRec(t1, t2);
}