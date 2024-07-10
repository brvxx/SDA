#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

static void TiroAllaFuneRec(int* data, int n, int i, int sum_curr, int sum_tot, int* diff_min, int* vcurr, int* vbest, int cnt, int* calls) {
	(*calls)++;
	
	if (cnt == n / 2) {
		int sum_2 = sum_tot - sum_curr; 
		int diff = abs(sum_curr - sum_2); 
		
		if (diff < *diff_min) {
			memcpy(vbest, vcurr, n * sizeof(int)); 
			*diff_min = diff; 
		}
		return; 
	}
	if (i == n) {
		return; 
	}

	// posso permettermi di non prednere il dato corrente se e solo se la count + i numeri che possso ancora prendere
	// da qui in poi senza contare questo mi permettono di arrivare a size/2 (obbiettivo) 

	if (n - i - 1 + cnt >= n / 2) { 
		vcurr[i] = 0; 
		TiroAllaFuneRec(data, n, i + 1, sum_curr, sum_tot, diff_min, vcurr, vbest, cnt, calls); 
	}

	vcurr[i] = 1; 
	TiroAllaFuneRec(data, n, i + 1, sum_curr + data[i], sum_tot, diff_min, vcurr, vbest, cnt + 1, calls); 
	vcurr[i] = 0; 

}


int main(int argc, char** argv) {
	if (argc == 1) {
		return 0; 
	}
	int* data = calloc(argc - 1, sizeof(int)); 

	int size = argc - 1; 

	for (int i = 1; i < argc; ++i) {
		char* endptr; 
		int num = strtol(argv[i], &endptr, 10); 
		data[i - 1] = num; 
	}
	
	int diff = INT_MAX; 
	int* vcurr = calloc(size, sizeof(int)); 
	int* vbest = calloc(size, sizeof(int));

	int sum = 0; 
	for (int i = 0; i < size; ++i) {
		sum += data[i]; 
	}
	int calls = 0; 
	TiroAllaFuneRec(data, size, 0, 0, sum, &diff, vcurr, vbest, 0, &calls);

	printf("{ "); 
	int cnt = 0; 
	for (int i = 0; i < size; ++i) {
		if (vbest[i] == 1) {
			++cnt; 
			if (cnt == size / 2) {
				printf("%d", data[i]); 
			}
			else {
				printf("%d, ", data[i]); 
			}
		}
	}
	printf(" }, { ");

	cnt = 0; 
	for (int i = 0; i < size; ++i) {
		if (vbest[i] == 0) {
			++cnt;
			if (cnt == size - size / 2) {
				printf("%d", data[i]);
			}
			else {
				printf("%d, ", data[i]);
			}
		}
	}
	printf(" }\n"); 
	printf("%d", calls); 
	return 0; 
}