#include "tree.h"

extern int CountDominant(const Node* t);

int main(void) {
	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t = TreeCreateRoot(arr + 9, 
					TreeCreateRoot(arr + 2,	
						TreeCreateRoot(arr, NULL, NULL),
						TreeCreateRoot(arr + 1, NULL, NULL)),
					TreeCreateRoot(arr + 4, 
						TreeCreateRoot(arr + 8, NULL, NULL),
						TreeCreateRoot(arr+ 3, NULL, NULL)));

	TreeWriteStdoutPreOrder(t);
	int res = CountDominant(t); 
	printf("il numero di nodi dominanti e': %d", res); 

	TreeDelete(t);

	return 0; 
}