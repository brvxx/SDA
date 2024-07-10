#include "tree.h"

extern Node* MergeTree(const Node* t1, const Node* t2);

int main(void) {
	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Node* t1 = TreeCreateRoot(arr + 2,
					TreeCreateRoot(arr + 5,
						TreeCreateRoot(arr + 8, NULL, NULL),
						TreeCreateRoot(arr + 2, 
							NULL, 
							TreeCreateRoot(arr + 4, NULL, NULL))),
					TreeCreateRoot(arr + 1,
						NULL,
						TreeCreateRoot(arr + 1, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* t2 = TreeCreateRoot(arr + 3,
					TreeCreateRoot(arr + 10, NULL, NULL),
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 9, NULL, NULL),
						TreeCreateRoot(arr + 1, NULL, NULL)));

	TreeWriteStdoutPreOrder(t2);
	printf("\n\n");

	Node* res = MergeTree(t1, t2); 
	TreeWriteStdoutPreOrder(res); 

	TreeDelete(t1);
	TreeDelete(t2);
	TreeDelete(res); 

	return 0;
}