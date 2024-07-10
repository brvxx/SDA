#include "tree.h"

static int SostituisciSommaRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0; 
	}

	int sum = t->value;
	sum += SostituisciSommaRec(TreeLeft(t));
	sum += SostituisciSommaRec(TreeRight(t));

	t->value = sum; 

	return t->value; 
}

void SostituisciSomma(Node* t) {

	SostituisciSommaRec(t); 
}