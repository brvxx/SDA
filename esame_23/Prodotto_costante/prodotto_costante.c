#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

static bool Check(int* vcurr, int n) {
	int prev = -1; 
	for (int i = 0; i < n; ++i) {
		int prod = 1; 
		for (int j = i * n; j < i * n + n; ++j) {
			prod *= vcurr[j]; 
		}
		if (prev == -1) {
			prev = prod; 
		}
		else if (prev != prod) {
			return false; 
		}
	}

	for (int i = 0; i < n; ++i) {
		int prod = 1;
		for (int j = i; j < n * n; j += n) {
			prod *= vcurr[j];
		}
		if (prev == -1) {
			prev = prod;
		}
		else if (prev != prod) {
			return false;
		}
	}

	return true; 
}

static void RisolviProdottoRec(int n, const int* s, int i, int* vcurr, int* vsol, bool* presi, int* nsol) {
	if (i == n) {
		if (Check(vcurr, (int)sqrt(n))) {	// soluzione accettabile trovata
			memcpy(vsol, vcurr, n * sizeof(int)); 
			(*nsol)++;
		}
		return;
	}

	for (int j = 0;j < n; ++j) {
		if (!presi[j]) {
			vcurr[i] = s[j]; 
			presi[j] = true;

			RisolviProdottoRec(n, s, i + 1, vcurr, vsol, presi, nsol); 

			presi[j] = false; 
		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* vcurr = calloc(n * n, sizeof(int)); 
	int* vsol = calloc(n * n, sizeof(int)); 
	bool* presi = calloc(n * n, sizeof(bool)); 

	int nsol = 0; 

	RisolviProdottoRec(n * n, s, 0, vcurr, vsol, presi, &nsol); 

	free(presi); 
	free(vcurr); 

	if (nsol == 0) {
		free(vsol); 
		return NULL;
	}
	else {
		return vsol;
	}
}