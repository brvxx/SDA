#include <stdlib.h>
#include <stdio.h>

extern int KthLeast(const int* v, size_t n, int k);

int main(void) {

	int arr[] = { 10, 7, 1, 6, 9, 0, 2, 3, 6 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	// stampa al fly del vettore
	for (size_t i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	int k = 2; 
	int res = KthLeast(arr, size, k);

	printf("il %d-esimo elemento piu' piccolo all'interno del vettore passato e': %d\n\n", k, res); 

	return 0; 
}