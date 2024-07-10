#include "tree.h"

extern const Node* Successore(const Node* t, const Node* n);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 3,
					TreeCreateRoot(arr + 2,
						TreeCreateRoot(arr + 5, NULL, NULL),
						TreeCreateRoot(arr + 7, NULL, NULL)),
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 6, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* n = TreeLeft(t1); 
	Node* res = Successore(t1, n); 

	ElemWriteStdout(TreeGetRootValue(res)); 

	TreeDelete(t1);

	return 0;
}