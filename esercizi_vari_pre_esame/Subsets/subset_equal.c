#include <stdlib.h> 
#include <stdio.h>

static void SubsetEqualRec(int n, int s, int i, int sum_curr, int* vcurr) {
	if (sum_curr == s) {
		printf("{ "); 
		for (int j = 0; j < n; ++j) {
			if (vcurr[j]) {
				printf("%d ", j + 1); 
			}
		}
		printf("}, "); 
		return; 
	}
	if (i == n) {
		return; 
	}
	
	vcurr[i] = 0; 
	SubsetEqualRec(n, s, i + 1, sum_curr, vcurr); 

	vcurr[i] = 1; 
	SubsetEqualRec(n, s, i + 1, sum_curr + i + 1, vcurr); 
	vcurr[i] = 0; 
}

void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return; 
	}
	int* vcurr = calloc(n, sizeof(int)); 

	SubsetEqualRec(n, s, 0, 0, vcurr); 

	free(vcurr); 
}