#include "tree.h"

static bool TreeContainsNode(const Node* tree, const Node* node) {
	if (tree == node) { // devo comparare gli indirizzi e non i valori 
		return true; 
	}
	if (TreeIsEmpty(tree)) {
		return false; 
	}

	return TreeContainsNode(TreeLeft(tree), node) || TreeContainsNode(TreeRight(tree), node); 
}

static void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, const Node** ancestor) {
	if (TreeContainsNode(t, n1) && TreeContainsNode(t, n2)) {
		*ancestor = t; 
	}
	else {
		return; 
	}
	if (TreeIsEmpty(t)) {
		return; 
	}

	LowestCommonAncestorRec(TreeLeft(t), n1, n2, ancestor); 
	LowestCommonAncestorRec(TreeRight(t), n1, n2, ancestor); 
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	if (TreeIsEmpty(t)) {
		return NULL; 
	}
	
	const Node* ancestor = t; 

	LowestCommonAncestorRec(t, n1, n2, &ancestor); 

	return ancestor; 
}