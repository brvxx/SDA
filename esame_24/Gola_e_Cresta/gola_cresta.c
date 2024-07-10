#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> 

static bool Check(int* vcurr, size_t n) {
	for (size_t i = 0; i + 2 < n; ++i) {
		if ((vcurr[i] < vcurr[i + 1] && vcurr[i + 1] > vcurr[i + 2]) ||
			(vcurr[i] > vcurr[i + 1] && vcurr[i + 1] < vcurr[i + 2])) {
			continue; 
		}
		else {
			return false; 
		}
	}
	return true; 
}

static void GolaCrestaRec(size_t n, int i, int* vcurr) {
	if (i == (int)n) {
		if (Check(vcurr, n)) {
			printf("("); 
			for (size_t j = 0; j < n - 1; ++j) {
				printf("%d, ", vcurr[j]);
			}
			printf("%d), ", vcurr[n - 1]);

		}
		return; 
	}

	for (int k = 0; k < 3; ++k) {
		vcurr[i] = k; 
		GolaCrestaRec(n, i + 1, vcurr);
	}

}

void GolaCresta(size_t n) {
	if (n < 3) {
		return; 
	}
	
	int* vcurr = calloc(n, sizeof(int)); 

	GolaCrestaRec(n, 0, vcurr);

	free(vcurr); 
}