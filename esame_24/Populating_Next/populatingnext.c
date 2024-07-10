#include "tree.h" 

static void PopulatingNextRec(Node* t, Node** prev) {
	if (TreeIsEmpty(t)) {
		return; 
	}
	
	PopulatingNextRec(TreeLeft(t), prev); 

	if (*prev != NULL) {
		(*prev)->next = t; 
	}
	*prev = t; 

	PopulatingNextRec(TreeRight(t), prev); 
}

void PopulatingNext(Node* t) {
	Node* prev = NULL; 

	PopulatingNextRec(t, &prev); 

	return; 
}