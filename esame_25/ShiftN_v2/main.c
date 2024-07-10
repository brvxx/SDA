#include "shift.h"

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	Item* l1 = ListCreateEmpty(); 
	for (int i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}
	ListWriteStdout(l1); 

	l1 = ShiftN(l1, 4); 

	ListWriteStdout(l1);
	
	ListDelete(l1); 
	return 0; 
}