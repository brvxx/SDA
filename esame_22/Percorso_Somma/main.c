#include "tree.h"

extern bool PercorsoSomma(Node* t, const ElemType* target);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 2,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 7, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)),
					TreeCreateRoot(arr + 3,
						TreeCreateRoot(arr + 2, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	bool res = PercorsoSomma(t1, &(ElemType){7});

	res ? printf("esiste il percorso\n\n") : printf("non esiste il percorso\n\n"); 

	TreeDelete(t1);

	return 0;
}