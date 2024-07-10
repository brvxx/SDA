#include <stdlib.h>

#include "list.h"


// funzione che rimuove la prima occorrenza di un elemento dalla lista --> approccio iterativo 
Item* ListRemove(const ElemType* e, Item* i) {
	Item* tmp = i;
	Item* prev = NULL;

	while (!ListIsEmpty(tmp)) {
		if (ElemCompare(e, ListGetHeadValue(tmp)) == 0) {
			break;
		}
		prev = tmp;
		tmp = ListGetTail(tmp);
	}

	if (!ListIsEmpty(tmp)) {
		if (prev == NULL) {
			Item* res = i->next;
			ElemDelete(&(i->value));
			free(i);
			return res;
		}
		else {
			prev->next = tmp->next;
			ElemDelete(&(tmp->value));
			free(tmp);
		}
	}

	return i;
}

// funzione che rimuove tutte le occorrenze di un elemento --> approccio iterativo 
Item* ListRemoveAll(const ElemType* e, Item* i) {
	Item* tmp = i;
	Item* tmp_2 = NULL;
	Item* prev = NULL;

	while (!ListIsEmpty(tmp)) {
		if (ElemCompare(e, ListGetHeadValue(tmp)) == 0) {
			if (prev == NULL) {
				i = ListGetTail(i); 
				ElemDelete(&(tmp->value)); 
				free(tmp); 
				tmp = i; 
			}
			else {
				// nota che non bisogna aggiornare prev, perchè eliminiamo l'item nella posizione corrente
				prev->next = tmp->next;
				tmp_2 = tmp; 
				tmp = ListGetTail(tmp); 
				ElemDelete(&(tmp_2->value));
				free(tmp_2);
			}
		}
		else {
			prev = tmp;
			tmp = ListGetTail(tmp);
		}
	}

	return i;
}

// funzione che rimuove la prima occorrenza di un elemento da una lista --> approccio ricorsivo 
Item* ListRemoveRec(const ElemType* e, Item* i) {
	if (ListIsEmpty(i)) {
		return i; 
	}
	if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
		Item* tmp = ListGetTail(i); 
		ElemDelete(&(i->value)); 
		free(i);
		return tmp; 
	}
	Item* tmp = ListInsertHead(ListGetHeadValue(i), ListRemoveRec(e, ListGetTail(i)));
	ElemDelete(&(i->value)); 
	free(i); 
	return tmp; 
}

// funzione che rimuove tutte le occorrenze di un elemento e da una lista --> approccio ricorsivo
Item* ListRemoveRecAll(const ElemType* e, Item* i) {
	if (ListIsEmpty(i)) {
		return i;
	}
	while (ElemCompare(e, ListGetHeadValue(i)) == 0) {
		Item* tmp = i;
		i = ListGetTail(i);
		ElemDelete(&(tmp->value));
		free(tmp);
	}
	Item* tmp = ListInsertHead(ListGetHeadValue(i), ListRemoveRecAll(e, ListGetTail(i)));
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
	
	ElemType arr1[] = { 12, 12, 3, 4, 3, 5, 5, 7 };
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	printf("lista passata alle varie funzioni: \n");
	Item* l1 = ListCreateFromVector(arr1, size1);
	ListWriteStdout(l1);
	printf("\n");

	ElemType target = 12; 
	l1 = ListRemoveAll(&target, l1); 
	ListWriteStdout(l1); 

	ListDelete(l1); 
	return 0; 
}