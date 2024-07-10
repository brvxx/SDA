#include "tree.h"

extern Node* BstInsert(const ElemType* e, Node* n);
extern Node* BstInsertRec(const ElemType* e, Node* n);

int main(void) {
	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// creazione dell'albero 
	Node* t = TreeCreateRoot(arr + 4,
				TreeCreateRoot(arr + 3,
					TreeCreateRoot(arr + 1, 
						TreeCreateRoot(arr + 1, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					NULL), 
				TreeCreateRoot(arr + 7, 
					TreeCreateRoot(arr + 5, NULL, NULL),
					TreeCreateRoot(arr + 8, NULL, NULL)));	

	TreeWriteStdoutInOrder(t); 

	t = BstInsertRec(arr + 6, t);
	TreeWriteStdoutInOrder(t);

	TreeDelete(t); 

	return 0;
}