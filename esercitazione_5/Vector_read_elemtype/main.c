#include "vettore.h"
#include "elemtype.h"

int main(void) {
	
	Vector* res = VectorRead("input_int_03.txt"); 

	printf("Vettore letto da file : ["); 
	for (size_t i = 0; i < res->size; ++i) {
		ElemWriteStdout(res->data + i);
		if (i + 1 != res->size) {
			printf(", ");
		}
	}
	printf("]\n\n");

	Vector* ses = VectorReadSorted("input_int_03.txt");
	printf("Vettore letto da file e ordinato : [");
	for (size_t i = 0; i < ses->size; ++i) {
		ElemWriteStdout(ses->data + i);
		if (i + 1 != ses->size) {
			printf(", ");
		}
	}
	printf("]\n");

	return 0; 
}