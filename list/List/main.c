#include <stdlib.h>

#include "elemtype.h"
#include "list.h"


Item* CreateListFromVector(const ElemType* v, size_t size) {
	Item* list = ListCreateEmpty(); 

	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(v + i, list);
	}

	return list; 
}

bool IsMemberRec(const ElemType* e, Item* i) {
	if (ListIsEmpty(i)) {
		return false; 
	}
	if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
		return true; 
	}
	return IsMemberRec(e, ListGetTail(i));
}

Item* RemoveDuplicates(Item* i) {
	
	Item* res = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		Item* tmp = res;
		const ElemType* head = ListGetHeadValue(i);

		while (!ListIsEmpty(tmp)) {
			if (ElemCompare(head, ListGetHeadValue(tmp)) == 0) {
				break; 
			}
			tmp = ListGetTail(tmp);
		}

		if (ListIsEmpty(tmp)) {
			res = ListInsertBack(head, res);
		}
		i = ListGetTail(i); 
	}
	return res; 
}

// sorting di una lista andando a cambiare i valori dei vari item (NON I PUNTATORI ALL'ITEM SUCCESSIVO)
Item* Sort(Item* i) {
	
	Item* tmp_1 = i;
	Item* tmp_2 = NULL;
	Item* min_pos = NULL;

	while (!ListIsEmpty(tmp_1)) {
		min_pos = tmp_1;
		tmp_2 = ListGetTail(tmp_1);

		while (!ListIsEmpty(tmp_2)) {
			if (ElemCompare(&min_pos->value, &tmp_2->value) > 0) {
				min_pos = tmp_2;
			}
			tmp_2 = ListGetTail(tmp_2);
		}
		if (min_pos != tmp_1) {
			ElemSwap(&min_pos->value, &tmp_1->value);
		}
		tmp_1 = ListGetTail(tmp_1);
	}

	return i;

}

int main(void) {

	ElemType arr[] = { 12, 3, 4, 3, 5, 5, 7 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]);
	ElemType target = 0; 

	Item* list = CreateListFromVector(arr, size);
	ListWriteStdout(list); 

	//bool res = IsMemberRec(&target, list); 
	//res ? printf("\nil numero %d e' presente nella lista\n\n", target) : printf("\nil numero %d non e' presente nella lista\n\n", target); 

	//list = ListInsertBack(arr + 2, list);
	//ListWriteStdout(list);


	//Item* new_list = RemoveDuplicates(list);
	//printf("\nla nuova lista privata di doppioni sara': \n\n");
	//ListWriteStdout(new_list);

	list = Sort(list); 
	ListWriteStdout(list); 

	ListDelete(list); 

	return 0; 
}