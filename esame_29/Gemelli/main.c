#include <stdbool.h>

#include "tree.h"

extern bool TreesAreTwins(const Node* t1, const Node* t2);

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

	bool res_1 = TreesAreTwins(TreeLeft(t1), TreeRight(t1));
	bool res_2 = TreesAreTwins(TreeLeft(t2), TreeRight(t2));

	res_1 ? printf("gli alberi 1 e 2 sono gemelli \n") : printf("gli alberi 1 e 2 non sono gemelli \n");
	res_2 ? printf("gli alberi 1 e 2 sono gemelli \n") : printf("gli alberi 1 e 2 non sono gemelli \n");

	TreeDelete(t1);
	TreeDelete(t2);

	return 0;
}