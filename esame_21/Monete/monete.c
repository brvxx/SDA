#include <stdlib.h>
#include <stdio.h>

static void CombinaMoneteRec(int b, int i, const int* m, int sum_curr, int size, int* vcurr, int* nsol) {
	if (sum_curr == b) {
		(*nsol)++; 
		for (int j = 0; j < size; ++j) {
			printf("%d ", vcurr[j]);
		}
		printf("\n"); 
		return; 
	}
	if (i == size) {
		return; 
	}

	for (int k = 0; k <= b; ++k) {
		vcurr[i] = k; 
		sum_curr += (k * m[i]); 

		if (sum_curr > b) {
			vcurr[i] = 0; 
			return; 
		}

		CombinaMoneteRec(b, i + 1, m, sum_curr, size, vcurr, nsol); 

		sum_curr -= (k * m[i]);
	}
}

int CombinaMonete(int b, const int* m, size_t m_size) {
	int* vcurr = calloc(m_size, sizeof(int)); 
	int nsol = 0; 

	CombinaMoneteRec(b, 0, m, 0, (int)m_size, vcurr, &nsol); 

	free(vcurr); 
	return nsol; 
}