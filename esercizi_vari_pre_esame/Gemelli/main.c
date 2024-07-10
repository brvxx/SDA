#include "tree.h"

extern bool TreesAreTwins(const Node* t1, const Node* t2);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 0,
		TreeCreateRoot(arr + 1,
			TreeCreateRoot(arr + 3, NULL, NULL),
			TreeCreateRoot(arr + 4, NULL, NULL)),
		TreeCreateRoot(arr + 2,
			TreeCreateRoot(arr + 5, NULL, NULL),
			TreeCreateRoot(arr + 6, NULL, NULL)));

	Node* t2 = TreeCreateRoot(arr + 0,
		TreeCreateRoot(arr + 1,
			TreeCreateRoot(arr + 3, NULL, NULL),
			TreeCreateRoot(arr + 4, NULL, NULL)),
		TreeCreateRoot(arr + 2,
			TreeCreateRoot(arr + 5, NULL, NULL),
			TreeCreateRoot(arr + 6, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);
	TreeWriteStdoutPreOrder(t2);

	bool res = TreesAreTwins(t1, t2); 

	res ? printf("i due alberi sono gemelli") : printf("i due alberi non sono gemelli"); 

	TreeDelete(t1);

	return 0;
}