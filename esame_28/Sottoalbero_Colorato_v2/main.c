#include "tree.h"

extern const Node* BiggestColoredTree(const Node* t);

int main(void) {

	ElemType arr[] = { 'r', 'g', 'b'};

	Node* t1 = TreeCreateRoot(arr + 0,
		TreeCreateRoot(arr + 1,
			TreeCreateRoot(arr + 1, NULL, NULL),
			TreeCreateRoot(arr + 1, NULL, NULL)),
		TreeCreateRoot(arr + 2,
			TreeCreateRoot(arr + 2, NULL, NULL),
			TreeCreateRoot(arr + 2, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* res = BiggestColoredTree(t1); 

	TreeWriteStdoutPreOrder(res); 

	TreeDelete(t1);

	return 0;
}