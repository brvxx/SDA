#include "tree.h"

Node* RemoveLeaves(Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL; 
	}
	if (TreeIsLeaf(t)) {
		TreeDelete(t);
		return NULL;
	}

	t->left = RemoveLeaves(TreeLeft(t)); 
	t->right = RemoveLeaves(TreeRight(t)); 

	return t;

}