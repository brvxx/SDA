#include "vettore.h"

int main(void) {


	int* data = calloc(5, sizeof(int));
	int arr[] = { 1, 2, 3, 4, 5 };
	
	for (size_t i = 0; i < 5; ++i) {
		data[i] = arr[i];
	}
	
	struct vettore c = { data, 5 };

	Push(&c, 12);
	int res = Pop(&c);

	return 0; 
}