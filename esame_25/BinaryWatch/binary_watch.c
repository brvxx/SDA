#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static bool CheckTime(int* vcurr, int* minuti, int* ore) {
	int min = 0; 
	int hrs = 0; 

	for (int i = 0; i < 5; ++i) {
		if (vcurr[i] == 1) {
			hrs += (int)pow(2,4 - i); 
		}
	}
	for (int i = 0; i < 6; ++i) {
		if (vcurr[5 + i] == 1) {
			min += (int)pow(2, 5 - i); 
		}
	}

	if (min < 60 && hrs < 24) {
		*minuti = min; 
		*ore = hrs; 
		return true; 
	}
	else {
		return false;
	}
}

static void ValidTimesRec(uint8_t n, int i, uint8_t cnt, int* vcurr) {
	if (cnt == n) {
		int min = 0; 
		int hrs = 0; 
		bool test = CheckTime(vcurr, &min, &hrs); 
		if (test) {
			printf("%02d:", hrs); 
			printf("%02d, ", min); 
		}
		return; 
	}

	if (i == 11) {
		return; 
	}

	vcurr[i] = 0; 
	ValidTimesRec(n, i + 1, cnt, vcurr); 

	vcurr[i] = 1; 
	ValidTimesRec(n, i + 1, cnt + 1, vcurr); 
	vcurr[i] = 0;
}


void ValidTimes(uint8_t n) {
	if (n > 11) {
		return; 
	}
	int* vcurr = calloc(11, sizeof(int)); 

	ValidTimesRec(n, 0, 0, vcurr); 

	free(vcurr); 

}