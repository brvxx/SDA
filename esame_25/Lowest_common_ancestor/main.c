#include "tree.h"

extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2);

int main(void) {

	ElemType arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

	Node* tree = TreeCreateRoot(arr + 7, 
						TreeCreateRoot(arr + 3, 
							TreeCreateRoot(arr + 0, NULL, NULL),
							TreeCreateRoot(arr + 2, NULL, NULL)),
						TreeCreateRoot(arr + 5,	
							TreeCreateRoot(arr + 1, NULL, NULL),
							TreeCreateRoot(arr + 6, NULL, NULL)));

	TreeWriteStdoutPreOrder(tree); 

	Node* n1 = TreeLeft(tree); 
	n1 = TreeLeft(n1); 

	Node* n2 = TreeLeft(tree); 
	n2 = TreeRight(n2); 

	printf("nodi di cui cercare il antenato:\n");
	ElemWriteStdout(TreeGetRootValue(n1)); 
	ElemWriteStdout(TreeGetRootValue(n2)); 

	printf("\n\nantenato: ");
	const Node* Ancestor = LowestCommonAncestor(tree, n1, n2); 
	ElemWriteStdout(TreeGetRootValue(Ancestor));
	printf("\n\n"); 


	TreeDelete(tree);

	return 0; 
}