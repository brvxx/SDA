#include "tree.h"

static void LevelSumRec(const Node* t, size_t level, size_t lvl_curr, int* sum) {
	if (lvl_curr > level || TreeIsEmpty(t)) {
		return; 
	}
	if (lvl_curr == level) {
		*sum += t->value; 
	}

	LevelSumRec(TreeLeft(t), level, lvl_curr + 1, sum); 
	LevelSumRec(TreeRight(t), level, lvl_curr + 1, sum);
}

int LevelSum(const Node* t, size_t level) {
	size_t lvl_curr = 0; 
	int sum = 0;
	LevelSumRec(t, level, lvl_curr, &sum); 
	return sum; 
}