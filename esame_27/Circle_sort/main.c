#include <stdlib.h>
#include <stdio.h>

extern void CircleSort(int* v, size_t v_size);

int main(void) {

	int vec[] = { 3, 6, 2, 9, 0, 7, 1, -4, 8, 10, 45, 100, 23, 88, -12, 37, -51 };
	size_t size = sizeof(vec) / sizeof(vec[0]);

	printf("[ "); 
	for (size_t i = 0; i < size; ++i) {
		printf("%d ", vec[i]);
	}
	printf("]\n\n");

	CircleSort(vec, size); 

	printf("[ ");
	for (size_t i = 0; i < size; ++i) {
		printf("%d ", vec[i]);
	}
	printf("]\n\n");

	return 0; 
}