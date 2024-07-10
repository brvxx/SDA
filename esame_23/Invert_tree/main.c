#include "tree.h"

extern Node* Invert(Node* t);

int main(void) {
	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Node* t1 = TreeCreateRoot(arr + 2,
					TreeCreateRoot(arr + 5,
						TreeCreateRoot(arr + 8, NULL, NULL),
						TreeCreateRoot(arr + 2,
							TreeCreateRoot(arr + 4, NULL, NULL),
							TreeCreateRoot(arr + 4, NULL, NULL))),
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 7, NULL, NULL),
						TreeCreateRoot(arr + 1, NULL, NULL)));

	TreeWriteStdoutInOrder(t1);
	printf("\n\n");
	
	t1 = Invert(t1); 

	TreeWriteStdoutInOrder(t1); 
	printf("\n\n"); 

	TreeDelete(t1);

	return 0;
}