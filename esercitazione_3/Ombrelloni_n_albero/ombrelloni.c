#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void OmbrelloniRec(int k, int n, int h, int* vcurr, int* v_check, int* nsol, int i) {

	for (int j = h; j < n; j++) {
		if (v_check[j] == 0) {
			vcurr[i] = j; 
			v_check[j] = 1;		  // current position 
			if (j != n - 1) {
				v_check[j + 1] = 1;   // next position
			}
			if (j != 0) {
				v_check[j - 1] = 1;   // previous position 
			}

			if (i < k - 1) {
				OmbrelloniRec(k, n, j + 1,  vcurr, v_check, nsol, i + 1);
			}
			else {
				(*nsol)++;
				printf("%4d)", *nsol);
				for (int l = 0; l < n; ++l) {
					bool h = 0;
					for (int m = 0; m < k; ++m) {
						if (vcurr[m] == l) {
							h = 1;
							break;
						}
					}
					printf(" %d", h);
				}
				printf("\n");
			}

			v_check[j] = 0;		  // current position 
			if (j != n - 1) {
				v_check[j + 1] = 0;   // next position
			}
			if (j != 0) {
				v_check[j - 1] = 0;   // previous position 
			}

		}

	}
	

}


int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0;
	}

	int* vcurr = calloc(k, sizeof(int));
	int* v_check = calloc(n, sizeof(int));
	int nsol = 0;
	int h = 0; 

	OmbrelloniRec(k, n, h, vcurr, v_check, &nsol, 0);
	
	free(vcurr);
	free(v_check);

	return nsol;
}