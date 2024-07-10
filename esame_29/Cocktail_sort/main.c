#include <stdlib.h>
#include <stdio.h>

extern void CocktailSort(int* v, size_t v_size);


int main(void) {

	int vec[] = { 2 };
	size_t v_size = sizeof(vec) / sizeof(vec[0]); 

	printf("[");
	for (size_t i = 0; i < v_size; ++i) {
		printf("%d ", vec[i]);
	}
	printf("]\n");

	CocktailSort(vec, v_size);

	printf("vettore ordianto: \n\n[");
	for (size_t i = 0; i < v_size; ++i) {
		printf("%d ", vec[i]);
	}
	printf("]\n");

	return 0; 
}