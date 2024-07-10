#include "tree.h"

extern Node* RemoveLeaves(Node* t);

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

	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // scritto già ordinato affinché sia BST 
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Node* res = TreeCreateFromVector(arr, size);


	TreeWriteStdoutPreOrder(res);
	printf("\n");

	res = RemoveLeaves(res); 
	TreeWriteStdoutPreOrder(res);

	return 0; 
}