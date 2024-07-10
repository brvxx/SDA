#include "tree.h"

void CountDominantRec(const Node* t, int* dom) {
	
	// nota che se un albero � NULL per come � implementata la isleaf sar� anche foglia 
	if (TreeIsLeaf(t)) {
		return; 
	}

	int sx = 0; 
	int dx = 0; 
	if (!TreeIsEmpty(TreeLeft(t))) {
		sx = t->left->value; 
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		dx = t->right->value;
	}

	if ((sx + dx) < t->value) {
		(*dom)++;
	}

	CountDominantRec(TreeLeft(t), dom);
	CountDominantRec(TreeRight(t), dom); 
}

int CountDominant(const Node* t) {
	int dominant = 0; 
	CountDominantRec(t, &dominant); 

	return dominant; 
}