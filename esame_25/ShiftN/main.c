#include "shift.h"

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Item* l1 = ListCreateEmpty(); 

	for (size_t i = 0; i < 9; ++i) {
		l1 = ListInsertBack(l1, arr + i); 
	}
	ListWriteStdout(l1);
	l1 = ShiftN(l1, 1);
	
	ListWriteStdout(l1); 


	ListDelete(l1); 

	return 0; 
}