#include "tree.h"

extern bool Cugini(const Node* t, int a, int b);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 1,
					TreeCreateRoot(arr + 2,
						TreeCreateRoot(arr + 3, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)),
					TreeCreateRoot(arr + 5,
						TreeCreateRoot(arr + 6, NULL, NULL),
						TreeCreateRoot(arr + 8, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	bool res = Cugini(t1, 3, 4); 

	res ? printf("i due nodi passati sono cugini") : printf("i due nodi passati non sono cugini");

	TreeDelete(t1);

	return 0;
}