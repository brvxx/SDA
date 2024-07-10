#include "tree.h"

extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);

int main(void) {
	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 6,
		TreeCreateRoot(arr + 4,
			TreeCreateRoot(arr + 0, NULL, NULL),
			TreeCreateRoot(arr + 5, NULL, NULL)),
		TreeCreateRoot(arr + 8,
			TreeCreateRoot(arr + 7, NULL, NULL),
			TreeCreateRoot(arr + 9, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	Node* t2 = TreeCreateRoot(arr + 1,
		TreeCreateRoot(arr + 0,
			TreeCreateRoot(arr + 9, NULL, NULL),
			TreeCreateRoot(arr + 1, NULL, NULL)),
		TreeCreateRoot(arr + 0,
			TreeCreateRoot(arr + 8, NULL, NULL),
			TreeCreateRoot(arr + 3, NULL, NULL)));

	TreeWriteStdoutPreOrder(t2);

	const ElemType* res_1 = BstTreeMin(t1);
	printf("il node di valore maggiore contiene l'elemento: ");
	ElemWriteStdout(res_1);
	printf("\n\n");

	const ElemType* res_2 = TreeMin(t2);
	printf("il node di valore maggiore contiene l'elemento: ");
	ElemWriteStdout(res_2);
	printf("\n\n");


	TreeDelete(t1);
	TreeDelete(t2);

	return 0;
}