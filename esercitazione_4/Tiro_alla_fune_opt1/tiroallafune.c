#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

void TiroAllaFune(int* set, int* vcurr, int* vbest, int* set_check, int i, int n, int sum1, int* sum_tot, int* diff_best, int* calls) {
	(*calls)++;
	for (int j = 0; j < n; ++j) { // nota che se al posto di 0 avessi messo i, sarebbe risultato un po' più ottimizzato
		if (set_check[j] == 0) {
			vcurr[i] = set[j];
			set_check[j] = 1;
			sum1 += set[j];

			if (i < n / 2 - 1) {
				TiroAllaFune(set, vcurr, vbest, set_check, i + 1, n, sum1, sum_tot, diff_best, calls);
			}
			else {
				if (abs(sum1 - (*sum_tot - sum1)) < *diff_best) {
					*diff_best = abs(sum1 - (*sum_tot - sum1));
					memcpy(vbest, vcurr, n / 2 * sizeof(int));
					int h = 0;
					for (int k = n / 2; k < n; ++k) {
						for (int l = h; l < n; ++l) {
							if (set_check[l] == 0) {
								vbest[k] = set[l];
								h++;
								break;
							}
							else {
								h++;
							}
						}
					}

				}
			}

			set_check[j] = 0;
			sum1 -= set[j];
		}
	}
}


int main(int argc, char** argv) {

	int n = argc - 1;
	int* set = calloc(n, sizeof(int));
	int* vcurr = calloc(n / 2, sizeof(int));
	int* vbest = calloc(n, sizeof(int));
	int* set_check = calloc(n, sizeof(int));

	char* endptr;
	int sum_tot = 0;
	for (int i = 0; i < argc - 1; ++i) {
		set[i] = strtol(argv[i + 1], &endptr, 10);
		sum_tot += set[i];
	}

	int i = 0;
	int sum1 = 0;
	int calls = 0;
	int diff_best = INT_MAX;
	TiroAllaFune(set, vcurr, vbest, set_check, i, n, sum1, &sum_tot, &diff_best, &calls);

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

	free(set);
	free(vcurr);
	free(vbest);
	free(set_check);

	return 0;
}