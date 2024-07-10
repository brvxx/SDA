#include "tree.h"

extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2);

int main(void) {

	ElemType arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	Node* t1 = TreeCreateRoot(arr + 0,
		TreeCreateRoot(arr + 1,
			TreeCreateRoot(arr + 3, NULL, NULL),
			TreeCreateRoot(arr + 2, NULL, NULL)),
		TreeCreateRoot(arr + 6,
			TreeCreateRoot(arr + 5, NULL, NULL),
			TreeCreateRoot(arr + 4, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* tmp1 = TreeLeft(t1); 
	tmp1 = TreeLeft(tmp1); 

	Node* tmp2 = TreeLeft(t1);
	tmp2 = TreeRight(tmp2);


	const Node* res = LowestCommonAncestor(t1, tmp1, tmp2);

	ElemWriteStdout(TreeGetRootValue(res)); 

	TreeDelete(t1);

	return 0;
}