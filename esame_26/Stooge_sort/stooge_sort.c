#include <stdlib.h>
#include <math.h>

static void Swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp;
}

static void StoogeRec(int* vector, int size) {

	if (vector[0] > vector[size - 1]) {
		Swap(vector + 0, vector + size - 1); 
	}

	if (size < 3) {
		return; 
	}

	// cast a double affinchè la divisione non produca 0
	int size_new =	(int)ceil((double)2 / 3 * size); 

	StoogeRec(vector, size_new);
	StoogeRec(vector + (size - size_new), size_new);
	StoogeRec(vector, size_new);
}

void Stooge(int* vector, size_t vector_size){
	if (vector_size == 0) {
		return; 
	}
	StoogeRec(vector, (int)vector_size);
}