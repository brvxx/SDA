#include <stdlib.h>
#include <math.h>

int* SolarCut(int A, size_t* sol_size) {

	int* res = NULL;
	int nsol = 0;
	while (A > 0) {
		int val = (int)sqrt(A);
		A -= val * val;
		++nsol;

		res = realloc(res, nsol * sizeof(int));

		res[nsol - 1] = val * val;
	}

	*sol_size = nsol;
	return res;
}