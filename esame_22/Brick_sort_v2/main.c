#include <stdlib.h>
#include <stdio.h>

extern void BrickSort(int* v, size_t v_size);

int main(void) {
	int arr[] = { 9, 8, 7, 6, 5, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	BrickSort(arr, (size_t)size);

	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	return 0;
}