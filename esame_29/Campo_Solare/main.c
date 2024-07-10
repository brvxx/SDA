#include <stdlib.h>
#include <stdio.h>

extern int* SolarCut(int A, size_t* sol_size);

int main(void) {

	size_t sol = 0; 
	int* res = SolarCut(12, &sol);

	printf("[ ");
	for (size_t i = 0; i < sol; ++i) {
		printf("%d ", res[i]);
	}
	printf("]\n");

	free(res); 
	return 0; 
}