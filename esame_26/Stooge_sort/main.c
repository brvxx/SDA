#include <math.h>
#include <stdio.h>

extern void Stooge(int* vector, size_t vector_size);

int main(void) {

	int v[] = { 4, 5, 1, 0, 4, 12, 9, 11, 2, 3, 4, 9, 453534, 69, 70, 2007, 20, 10, 2007 }; 
	int size = sizeof(v) / sizeof(v[0]); 
	
	printf("[ "); 
	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]);
	}
	printf("]\n\n"); 

	Stooge(v, (size_t)size); 

	printf("[ ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]);
	}
	printf("]\n\n");

	return 0; 
}