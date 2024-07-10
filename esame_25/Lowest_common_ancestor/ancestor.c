#include <stdbool.h>

#include "tree.h"


bool TreeContainsNode(const Node* tree, const Node* node) {

	if (TreeIsEmpty(tree)) {
		return false; 
	}

	if (tree == node) {
		return true; 
	}

	return TreeContainsNode(TreeLeft(tree), node) || TreeContainsNode(TreeRight(tree), node);
}

static void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, const Node** res) {
	if (TreeIsEmpty(t)) {
		return; 
	}
	
	// node is ancestor 
	if (TreeContainsNode(t, n1) && TreeContainsNode(t, n2)) {
		*res = t; 
	}
	else {	// current node is not ancestor
		return; 
	}

	LowestCommonAncestorRec(TreeLeft(t), n1, n2, res); 
	LowestCommonAncestorRec(TreeRight(t), n1, n2, res);
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	const Node* res = t; 
	LowestCommonAncestorRec(t, n1, n2, &res); 
	return res; 
}