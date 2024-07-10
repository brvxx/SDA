#include "tree.h"

static bool SearchTargetSum(const Node* root, int target, const Node* call) {
	if (TreeIsEmpty(root)) {
		return false; 
	}
	if (call != root && root->value + call->value == target) {
		return true; 
	}
	return SearchTargetSum(TreeLeft(root), target, call) || SearchTargetSum(TreeRight(root), target, call); 
}

static bool CheckSumNRec(const Node* t, const Node* root, int n) {
	if (TreeIsEmpty(t)) {
		return false; 
	}
	if (SearchTargetSum(root, n, t)) {
		return true;
	}

	return CheckSumNRec(TreeLeft(t), root, n) || CheckSumNRec(TreeRight(t), root, n);
}

bool CheckSumN(const Node* t, int n) {
	return CheckSumNRec(t, t, n); 
}