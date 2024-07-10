#include <stdlib.h>
#include <stdio.h>

extern void InsertionSort(int* v, size_t v_size);

int main(void) {

	int v[] = { 4, 3, 2, 1 }; 
	int size = sizeof(v) / sizeof(v[0]); 

	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]); 
	}
	printf("\n"); 

	InsertionSort(v, (size_t)size); 

	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0; 
}