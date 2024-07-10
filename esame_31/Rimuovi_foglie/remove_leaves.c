#include "tree.h"

Node* RemoveLeavesRec(Node* t) {
	if (TreeIsLeaf(t)) {
		TreeDelete(t); 
		return NULL; 
	}
	
	if (!TreeIsEmpty(TreeLeft(t))) {
		t->left = RemoveLeavesRec(TreeLeft(t));
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		t->right = RemoveLeavesRec(TreeRight(t));
	}

	return t; 
}

Node* RemoveLeaves(Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL; 
	}
	t = RemoveLeavesRec(t);
	return t; 
}