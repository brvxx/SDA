#include <stdio.h>

#include "list.h"

Item* ListReverse(Item* list) {
	Item* prev = NULL; 
	Item* curr = list; 
	Item* next = NULL; 

	while (!ListIsEmpty(curr)) {
		// salviamo nel puntatore a item la posizione successiva alla corrente 
		next = curr->next; 

		// invertiamo il collegamento tra item
		curr->next = prev; 

		// ci spostiamo alla prossima coppia di items
		prev = curr; 
		curr = next; 
	}
	return prev; 
}

Item* CreateListFromVector(const ElemType* v, size_t size) {
	Item* res = ListCreateEmpty(); 
	for (size_t i = 0; i < size; ++i) {
		res = ListInsertBack(res, v + i); 
	}
	return res; 
} 

int main(void) {

	ElemType arr[] = { 7, 8 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	// ricorda che anche se il parametro della funzione è const non devi passarlo const il vettore, sarà 
	// la funzione stessa ad interpretarlo come tale, ma se il valore di ritorno di una funzione fosse 
	// const allora bisogna creare una variabile const per non perdere la constness
	
	Item* l1 = CreateListFromVector(arr, size); 
	printf("lista di partenza:\n");
	ListWriteStdout(l1); 
	
	l1 = ListReverse(l1); 
	printf("\n\nlista reverse:\n"); 
	ListWriteStdout(l1);


	ListDelete(l1); 

	return 0; 
}