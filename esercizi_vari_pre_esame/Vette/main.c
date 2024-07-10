#include "list.h"

extern int ContaVette(const Item* i);

int main(void) {

	ElemType arr[] = { 7, 2, 5 ,4 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();

	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	ListWriteStdout(l1);

	int res = ContaVette(l1);

	printf("numero totale di vette nella lista: %d", res);

	ListDelete(l1);

	return 0;
}