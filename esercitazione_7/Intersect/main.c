#include "list.h"
#include "elemtype.h"

extern Item* Intersect(const Item* i1, const Item* i2); 

Item* CreateListFromVector(const ElemType* vec, size_t size) {
	Item* res = ListCreateEmpty(); 
	
	for (size_t i = 0; i < size; ++i) {
		res = ListInsertBack(res, vec + i);
	}
	
	return res; 
}

int main(void) {

	ElemType vec1[] = { 3, 4, 2, 0, 45, 1, 3 };
	ElemType vec2[] = { 8, 5, 2, 3, 45, 7 };
	size_t vec1_size = sizeof(vec1) / sizeof(vec1[0]); 
	size_t vec2_size = sizeof(vec2) / sizeof(vec2[0]);

	Item* l1 = CreateListFromVector(vec1, vec1_size);
	Item* l2 = CreateListFromVector(vec2, vec2_size);

	ListWriteStdout(l1);
	ListWriteStdout(l2);

	Item* res = Intersect(l1, l2); 
	
	ListWriteStdout(res);

	ListDelete(l1);
	ListDelete(l2); 
	ListDelete(res); 

	return 0; 
}