#include <stdbool.h>

#include "tree.h"

extern bool TreeIsMirror(const Node* t);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 0,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 2, NULL, NULL),
						TreeCreateRoot(arr + 4, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* t2 = TreeCreateRoot(arr + 0,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)));

	TreeWriteStdoutPreOrder(t2);
	printf("\n\n");

	bool res_1 = TreeIsMirror(t1);
	bool res_2 = TreeIsMirror(t2); 
	
	res_1 ? printf("l'albero 1 e' specchiato\n") : printf("l'albero 1 non e' specchiato\n");
	res_2 ? printf("l'albero 2 e' specchiato\n") : printf("l'albero 2 non e' specchiato\n");
	
	TreeDelete(t1);
	TreeDelete(t2);

	return 0; 
}