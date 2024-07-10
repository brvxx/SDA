#include "tree.h"

static void InvertRec(Node* t) {
	if (TreeIsLeaf(t)) {
		return; 
	}
	Node* tmp = TreeLeft(t); 
	t->left = TreeRight(t); 
	t->right = tmp; 

	InvertRec(TreeLeft(t)); 
	InvertRec(TreeRight(t)); 
}

Node* Invert(Node* t) {
	InvertRec(t); 
	return t; 
}