#include "tree.h"

static void InvertRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return; 
	}

	Node* tmp = t->left; 
	t->left = t->right; 
	t->right = tmp; 

	InvertRec(TreeLeft(t)); 
	InvertRec(TreeRight(t)); 
}

Node* Invert(Node* t) {
	InvertRec(t); 
	return t; 
}