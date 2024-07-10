#include <stdio.h>
#include <stdlib.h>

void BacktrackSubset(int n, int i, int* vcurr, int* nsol) {

	if (i == n) {

		printf("%d) [", *nsol);
		(*nsol)++; 

		for (int j = 0; j < n; ++j) {
			printf("%d ", vcurr[j]);
		}
		puts("]\n");

		return;
	}

	for (int j = 0; j < 2; ++j) {
		vcurr[i] = j; 

		BacktrackSubset(n, i + 1, vcurr, nsol);
	}
}


int main(void) {

	int elements = 4;
	int i = 0; 
	int* sln = calloc(elements, 1);
	int nsol = 0; 

	puts("list of possible subsets: \n"); 
	BacktrackSubset(elements, i, sln, &nsol);
	printf("total amount of subsets: %d (2^%d)", nsol, elements);

	return 0; 
}