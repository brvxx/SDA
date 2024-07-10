#include <stdlib.h>
#include <stdbool.h>

static void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void CocktailSort(int* v, size_t v_size) {
	bool done = false; 

	int start = 0; 
	int end = (int)v_size - 1; 
	while (!done) {
		done = true; 
		for (int i = start; i < end; ++i) {
			if (v[i] > v[i + 1]) {
				swap(v + i, v + i + 1); 
				done = false; 
			}
		}
		--end;
		for (int i = end; i > start; --i) {
			if (v[i] < v[i - 1]) {
				swap(v + i, v + i - 1);
				done = false;
			}
		}
		++start; 
	}
}