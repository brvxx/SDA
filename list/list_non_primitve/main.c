// in questo file vengono mostrate l'implementazioni di varie funzioni utili 
// per lavorare sulle liste ma non definibili come primitive

#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

// funzione che ci dice se un determinato elemtype è presente in un qualche item all'interno della 
// lista 
bool is_member(const ElemType* e, const Item* i) {
	while (!ListIsEmpty(i)) {
		if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
			return true; 
		}
		i = ListGetTail(i); 
	}
	return false; 
}

// funzione che calcola la lunghezza della lista in modo ricorsivo 
int ListLenghtRec(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0; 
	}
	return 1 + ListLenghtRec(ListGetTail(i));
}

// funzione che calcola la lunghezza della lista in modo iterativo 
int ListLenght(const Item* i) {
	int len = 0; 
	
	while (!ListIsEmpty(i)) {
		++len; 
		i = ListGetTail(i);
	}

	return len; 
}

// funzione che collega tra loro due liste, la seconda verrà messa in coda alla prima.
// ricorda che le la nuova lista non è semplicemente il collegamento tra le due passate,
// in nessun modo viene allocata memoria.    
// 
// approccio iterativo
Item* ListAppend(Item* i1, Item* i2) {
	Item* tmp = i1; 

	while (!ListIsEmpty(ListGetTail(tmp))) {
		tmp = ListGetTail(tmp);
	}

	tmp->next = i2;
	return i1; 

}

//append con approccio ricorsivo 
Item* ListAppendRec(Item* i1, Item* i2) {
	if (ListIsEmpty(i1)) {
		return i2; 
	}
	Item* tmp = ListInsertHead(ListGetHeadValue(i1), ListAppendRec(ListGetTail(i1), i2)); 
	ElemDelete(&(i1->value)); 
	free(i1); 
	return tmp; 
}

// funzione di copia per le liste (alloca memoria) 
//
// implementazione ricorsiva
Item* ListCopyRec(Item* i) {
	if (ListIsEmpty(i)) {
		return i; 
	}
	
	return ListInsertHead(ListGetHeadValue(i), ListCopyRec(ListGetTail(i)));
}

// funzione di copia (ricorsiva) 
Item* ListCopy(Item* i) {
	Item* res = ListCreateEmpty(); 
	while (!ListIsEmpty(i)) {
		res = ListInsertBack(res, ListGetHeadValue(i)); 
		i = ListGetTail(i); 
	}
	return res; 
}

// funzione che a partire da un vettore di elemtype crea una lista di elemtype 
Item* ListCreateFromVector(const ElemType* v, size_t size) {
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	return list;
}

int main(void) {

	ElemType arr1[] = { 12, 3, 4, 3, 5, 5, 7 };
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
	
	printf("lista passata alle varie funzioni: \n"); 
	Item* l1 = ListCreateFromVector(arr1, size1); 
	ListWriteStdout(l1); 
	printf("\n"); 

	// is_member
	ElemType target = 8; 
	bool res = is_member(&target, l1); 
	res ? printf("l'elemento %d e' presente all'interno della lista\n\n", target) : printf("l'elemento %d non e' presente nella lista\n\n", target); 

	// lenght
	int len = ListLenghtRec(l1); 
	printf("lunghezza della lista (ricorsivo): %d\n", len); 
	len = ListLenght(l1); 
	printf("lunghezza della lista (iterativo): %d\n\n\n", len);
	
	// append 
	ElemType arr2[] = { 0, 1, 2, 3, 4, 5, 6 };
	size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

	printf("seconda lista: \n");
	Item* l2 = ListCreateFromVector(arr2, size2);
	ListWriteStdout(l2); 
	
	Item* l3 = ListAppendRec(l1, l2); 
	printf("terza lista creata concatenando le prime due:\n");
	ListWriteStdout(l3); 

	// copy
	printf("\n\ncopia della lista: \n");
	Item* l4 = ListCopy(l3); 
	ListWriteStdout(l4); 

	ListDelete(l3);
	ListDelete(l4); 
	
	return 0;
}