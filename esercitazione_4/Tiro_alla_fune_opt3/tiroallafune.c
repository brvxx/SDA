#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

void TiroAllaFune(int* set, int* vcurr, int* vbest, int i, int n, int k, int cnt, int sum1, int* sum_tot, int* diff_best, int* calls) {
	(*calls)++;
	if (cnt == k) {
		for (int m = i; m < n; m++) {
			vcurr[m] = 0;
		}
		if (abs(sum1 - (*sum_tot - sum1)) < *diff_best) {
			*diff_best = abs(sum1 - (*sum_tot - sum1));
			int h = 0;
			int l = n / 2;
			for (int j = 0; j < n; ++j) {
				if (vcurr[j] == 1) {
					vbest[h] = set[j];
					++h;
				}
				else {
					vbest[l] = set[j];
					++l;
				}
			}

		}
		return;
	}

	if (cnt + (n - 1 - i) >= k) {
		vcurr[i] = 0;
		TiroAllaFune(set, vcurr, vbest, i + 1, n, k, cnt, sum1, sum_tot, diff_best, calls);
	}
	sum1 += set[i];
	vcurr[i] = 1;
	TiroAllaFune(set, vcurr, vbest, i + 1, n, k, cnt + 1, sum1, sum_tot, diff_best, calls);
}


int main(int argc, char** argv) {

	int n = argc - 1;
	int* set = calloc(n, sizeof(int));
	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));

	// reading the values from command line via the strtol func 
	char* endptr;
	int sum_tot = 0;
	for (int i = 0; i < argc - 1; ++i) {
		set[i] = strtol(argv[i + 1], &endptr, 10);
		sum_tot += set[i];
	}

	int i = 0;
	int cnt = 0;
	int sum1 = 0;
	int calls = 0;
	int k = n / 2;
	int diff_best = INT_MAX;
	TiroAllaFune(set, vcurr, vbest, i, n, k, cnt, sum1, &sum_tot, &diff_best, &calls);

	// printing of the optimal solution 
	printf("{");
	for (int j = 0; j < n / 2; ++j) {
		if (j == n / 2 - 1) {
			printf(" %d", vbest[j]);
		}
		else {
			printf(" %d,", vbest[j]);
		}
	}
	printf(" }, {");
	for (int j = n / 2; j < n; ++j) {
		if (j == n - 1) {
			printf(" %d", vbest[j]);
		}
		else {
			printf(" %d,", vbest[j]);
		}
	}
	printf(" }");
	printf("\ntotale chiamate a funzione: %d", calls);

	// freeing dinamically allocated memory
	free(set);
	free(vcurr);
	free(vbest);

	return 0;
}