#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

extern bool* OptimalIllumination(int M, int R, const int* light,size_t light_size);

int main(void) {

	int M = 10; 
	int R = 3; 
	int arr[] = { 2, 7, 9 };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	bool* res = OptimalIllumination(M, R, arr, size); 

	printf("soluzione ottima: ");
	for (size_t i = 0; i < size; ++i) {
		res[i] ? printf(" 1 ") : printf(" 0 ");
	}
	printf("\n\n"); 

	return 0; 
}