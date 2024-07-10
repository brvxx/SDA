#include <stdlib.h>
#include <stdio.h>

extern int BinarySearch(const int* v, size_t v_size, int value);

int main(void) {

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	int target = 12;
	int res = BinarySearch(arr, size, target);

	if (res == -1) {
		printf("il valore %d non e' presente nel vettore passato\n", target); 
	}
	else {
		printf("il valore %d e' presente nel vettore in posizione %d \n", target, res + 1); 
	}

	return 0; 
}