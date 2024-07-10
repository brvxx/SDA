#include <stdlib.h>
#include <stdbool.h>

static void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp;
}

static bool CircleSortRec(int* v, int first, int last) {
	if (first == last) {
		return true; 
	}

	bool test = true; 
	int start = first; 
	int end = last;

	while (start < end) {
		if (v[start] > v[end]) {
			swap(v + start, v + end); 
			test = false; 
		}
		++start; 
		--end; 
	}

	int mid = (first + last) / 2;

	if ((first + last) % 2 == 0 && (v[mid] > v[mid + 1])) {
		swap(v + mid, v + mid + 1); 
		test = false;
	}
		
	return CircleSortRec(v, first, mid) && CircleSortRec(v, mid + 1, last) && test;
	
}

void CircleSort(int* v, size_t v_size) {
	if (v_size == 0) {
		return;
	}

	while (!CircleSortRec(v, 0, (int)v_size - 1)) {}
}