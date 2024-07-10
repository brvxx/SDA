#include "reverse.h"

Item* CreateListFromVector(const ElemType* v, size_t size) {
	Item* res = ListCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		res = ListInsertBack(res, v + i);
	}
	return res;
}

int main(void) {

	ElemType vec[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t size = sizeof(vec) / sizeof(vec[0]);

	Item* l1 = CreateListFromVector(vec, size);
	ListWriteStdout(l1);

	int left = 3;
	l1 = Reverse(l1, left);
	ListWriteStdout(l1);

	ListDelete(l1);

	return 0;
}