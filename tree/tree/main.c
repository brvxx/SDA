#include <stdlib.h>

#include "elemtype.h"
#include "tree.h"


// funzione che crea l'albero binario leggendo un vettore come se quella fosse 
// la sua vista in ampiezza. 

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

int main(void) {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

    Node* t1 = TreeCreateFromVector(arr, size); 
    TreeWriteStdoutPreOrder(t1);
    TreeWriteStdoutPostOrder(t1); 
    TreeWriteStdoutInOrder(t1); 

    TreeDelete(t1); 

    return 0; 
}