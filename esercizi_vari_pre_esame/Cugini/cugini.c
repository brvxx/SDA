#include "tree.h"

static void CuginiRec(const Node* t, int a, int b,const Node* parent, const Node** parent_a, const Node** parent_b, int lvl_curr, int* lvl_a, int* lvl_b) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (t->value == a) {
		*parent_a = parent;
		*lvl_a = lvl_curr;
	}
	if (t->value == b) {
		*parent_b = parent;
		*lvl_b = lvl_curr;
	}

	CuginiRec(TreeLeft(t), a, b, t, parent_a, parent_b, lvl_curr + 1, lvl_a, lvl_b);
	CuginiRec(TreeRight(t), a, b, t, parent_a, parent_b, lvl_curr + 1, lvl_a, lvl_b);
}


bool Cugini(const Node* t, int a, int b) {
	const Node* parent_a = TreeCreateEmpty(); 
	const Node* parent_b = TreeCreateEmpty(); 
	
	int lvl_a = 0; 
	int lvl_b = 0; 
	
	
	CuginiRec(t, a, b, 0, &parent_a, &parent_b, 0, &lvl_a, &lvl_b); 

	if ((parent_a != parent_b) && (lvl_a == lvl_b)) {
		return true; 
	}
	return false;
}