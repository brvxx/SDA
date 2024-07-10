#include <stdlib.h>

#include "list.h"


// funzione che inserisce all'interno di una lista ORDINATA un elemento nella sua corretta 
// posizione --> approccio iterativo
Item* ListInsertOrdered(const ElemType* e, Item* i) {
	Item* tmp = i; 
	Item* prev = NULL; 
	Item* new_item = ListInsertHead(e, ListCreateEmpty());
	
	while (!ListIsEmpty(tmp) && ElemCompare(ListGetHeadValue(tmp), e) < 0) {
		prev = tmp; 
		tmp = ListGetTail(tmp); 
	}
	if (prev == NULL) {
		return ListInsertHead(e, i); 
	}
	else {
		prev->next = new_item; 
		new_item->next = tmp; 
	}
	return i; 
}

// funzione che inserisce all'interno di una lista ORDINATA un elemento nella sua corretta
// posizione --> approccio ricorsivo
Item* ListInsertOrderedRec(const ElemType* e, Item* i) {

	// se ho finito la lista allora metterò e alla fine con un inserthead(e, i) dove i sarà NULL, invece se 
	// la testa della lista è maggiore o uguale all'elemento e, creo una lista che ha come testa e, e come restanti 
	// elementi quelli appartenenti ad i, e ritorno questa lista.
	if (ListIsEmpty(i) || ElemCompare(ListGetHeadValue(i), e) >= 0) {
		return ListInsertHead(e, i);
	}

	Item* tmp = ListInsertHead(ListGetHeadValue(i), ListInsertOrderedRec(e, ListGetTail(i)));
	ElemDelete(&(i->value)); 
	free(i); 
	
	return tmp; 
}

Item* ListCreateFromVector(const ElemType* v, size_t size) {
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	return list;
}

int main(void) {

	ElemType arr1[] = { 3, 4, 5, 7, 9, 12, 13, 13, 15, 19 };
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	printf("lista passata alle varie funzioni: \n");
	Item* l1 = ListCreateFromVector(arr1, size1);
	ListWriteStdout(l1);
	printf("\n");

	ElemType e = 22;
	l1 = ListInsertOrderedRec(&e, l1); 


	ListWriteStdout(l1);
	ListDelete(l1);
	return 0;
}