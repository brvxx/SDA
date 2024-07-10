#include "tree.h"

extern Node* Invert(Node* t);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 0,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 3, NULL, NULL),
						TreeCreateRoot(arr + 5, NULL, NULL)),
					TreeCreateRoot(arr + 7,
						TreeCreateRoot(arr + 2, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* res = Invert(t1); 

	TreeWriteStdoutPreOrder(res); 

	TreeDelete(t1);

	return 0;
}