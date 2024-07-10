#include "tree.h"

bool TreesAreTwins(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true; 
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false; 
	}

	return TreesAreTwins(TreeLeft(t1), TreeLeft(t2)) && TreesAreTwins(TreeRight(t1), TreeRight(t2)); 
}