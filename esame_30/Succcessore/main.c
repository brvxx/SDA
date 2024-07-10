#include "tree.h"

extern const Node* Successore(const Node* t, const Node* n);

Node* TreeCreateFromVectorRec(const int* arr, size_t size, int i) {
	// caso base, sto provando ad aggiungere un nodo ma non ci sono 
	// più elementi del vettore da aggiungere. 
	if (i >= size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(arr, size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(arr, size, i * 2 + 2);

	return TreeCreateRoot(arr + i, l, r);
}

Node* TreeCreateFromVector(const int* arr, size_t size) {
	return TreeCreateFromVectorRec(arr, size, 0);
}

int main(void) {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Node* tree = TreeCreateFromVector(arr, size);
	TreeWriteStdoutPreOrder(tree);
	printf("\n\n"); 

	// prendo un node a caso dell'albero
	Node* target = tree; 
	target = TreeLeft(target); 
	target = TreeRight(target); 
	target = TreeLeft(target);
	
	printf("valore del nodo da maggiorare: "); 
	ElemWriteStdout(TreeGetRootValue(target)); 
	printf("\n"); 

	const Node* res = Successore(tree, target); 
	printf("valore del maggiorante: ");
	ElemWriteStdout(TreeGetRootValue(res));
	printf("\n\n"); 

	TreeDelete(tree); 

	return 0; 
}