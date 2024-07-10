#include "tree.h"

static bool TreesAreTwinsRec(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true; 
	}
	
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return TreesAreTwinsRec(TreeLeft(t1), TreeLeft(t2)) && TreesAreTwinsRec(TreeRight(t1), TreeRight(t2));
}


bool TreesAreTwins(const Node* t1, const Node* t2) {
	return TreesAreTwinsRec(t1, t2); 
}