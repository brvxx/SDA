#include "list.h"
#include "elemtype.h"

const ElemType* MaxElement(const Item* i);

Item* CreateListFromVector(const ElemType* vec, size_t size) {
	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		res = ListInsertBack(res, vec + i);
	}

	return res;
}

int main(void) {

	ElemType vec1[] = { 3, 4, 2, 0, 45, 1, 3 };
	size_t size_1 = sizeof(vec1) / sizeof(vec1[0]);

	Item* l1 = CreateListFromVector(vec1, size_1); 
	const ElemType* res = MaxElement(l1);
	
	printf("cerchiamo l'elemento piu' grande all'interno della seguente lista:\n");
	ListWriteStdout(l1); 
	printf("\n");
	printf("l'elemento di valore maggiore e': ");
	ElemWriteStdout(res); 
	printf("\n\n");

	ListDelete(l1); 

	return 0;
}