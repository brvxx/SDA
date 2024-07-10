#include <string.h>

#include "list.h"

Item* Filtra(const Item* i, const char* city) {
	Item* res = ListCreateEmpty(); 
	while (!ListIsEmpty(i)) {
		if (strcmp(i->value.city, city) == 0) {
			res = ListInsertBack(res, ListGetHeadValue(i));
		}
		i = ListGetTail(i); 
	}

	return res; 
}

Item* Reverse(const Item* i) {
	Item* res = ListCreateEmpty(); 
	while (!ListIsEmpty(i)) {
		res = ListInsertHead(ListGetHeadValue(i), res); 
		i = ListGetTail(i); 
	}
	return res; 
}

Item* Append(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty(); 

	while (!ListIsEmpty(i1)) {
		res = ListInsertBack(res, ListGetHeadValue(i1));
		i1 = ListGetTail(i1); 
	}
	while (!ListIsEmpty(i2)) {
		res = ListInsertBack(res, ListGetHeadValue(i2));
		i2 = ListGetTail(i2);
	}

	return res;
}

Item* AppendMod(Item* i1, Item* i2) {
	if (!i1 && !i2) {
		return NULL;
	}
	else if (!i1) {
		return i2; 
	}
	
	Item* tmp = i1; 
	while (!ListIsEmpty(ListGetTail(tmp))) {
		tmp = ListGetTail(tmp); 
	}
	tmp->next = i2; 
	return i1; 
}
