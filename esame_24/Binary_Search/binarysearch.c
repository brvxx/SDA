#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {
	int first = 0; 
	int last = v_size - 1; 

	while (first <= last) {
		int mid = (first + last) / 2;
		
		if (v[mid] == value) {
			return mid; 
		}
		else if (v[mid] > value) {
			last = mid - 1; 
		}
		else {	// v[mid] < value
			first = mid + 1; 
		}
	}
	return -1; 
}