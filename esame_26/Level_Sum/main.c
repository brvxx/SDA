#include "tree.h"

extern int LevelSum(const Node* t, size_t level);

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

	TreeWriteStdoutPreOrder(t1);
	printf("\n\n");

	size_t lvl = 3; 
	int res = LevelSum(t1, lvl);

	printf("la somma degli elementi del livello %zu dell'albero e': %d\n\n", lvl, res);


	TreeDelete(t1);

	return 0;
}