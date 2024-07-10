#include "tree.h"

extern void PopulatingNext(Node* t);

void TreeWriteThroughNext(Node* t) {
	printf("stampa albero attraverso i next:\t");
	while (!TreeIsEmpty(t)) {
		ElemWriteStdout(TreeGetRootValue(t)); 
		t = t->next;
		printf("\t"); 
	}
}

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 3,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 0, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					TreeCreateRoot(arr + 5,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 6, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	PopulatingNext(t1); 

	Node* tmp = TreeLeft(t1); 
	tmp = TreeLeft(tmp); 

	TreeWriteThroughNext(tmp);

	TreeDelete(t1);

	return 0;
}