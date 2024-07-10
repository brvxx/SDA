#include "tree.h"

extern bool CheckSumN(const Node* t, int n);

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 0,
					TreeCreateRoot(arr + 1,
						TreeCreateRoot(arr + 4, NULL, NULL),
						TreeCreateRoot(arr + 2, NULL, NULL)),
					TreeCreateRoot(arr + 3,
						TreeCreateRoot(arr + 7, NULL, NULL),
						TreeCreateRoot(arr + 5, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	int target = 12;
	bool res = CheckSumN(t1, target); 

	res ? printf("esistono all'interno dell'albero due nodi distinti la cui somma fa: %d", target) :
		printf("esistono all'interno dell'albero due nodi distinti la cui somma fa: %d", target); 

	TreeDelete(t1);

	return 0;
}