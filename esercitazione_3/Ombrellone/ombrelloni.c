#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void OmbrelloniRec(int k, int n, bool* vcurr, int* nsol, int i, int count) {

	if (count == k) {
		(*nsol)++;
		printf("%4d)", *nsol);
		for (int j = 0; j < i; ++j) {
			printf(" %d", vcurr[j]);
		}
		for (int l = i; l < n; ++l) {
			printf(" 0");
		}
		printf("\n");
		return;
	}
	if (i == n) {
		return;
	}

	vcurr[i] = 0; 
	OmbrelloniRec(k, n, vcurr, nsol, i + 1, count);

	if ((vcurr[i - 1] == 0) || (i == 0)) {
		vcurr[i] = 1;
		OmbrelloniRec(k, n, vcurr, nsol, i + 1, count + 1);
	}
}



int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0; 
	}

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0; 

	OmbrelloniRec(k, n, vcurr, &nsol, 0, 0);
	free(vcurr);

	return nsol; 
}