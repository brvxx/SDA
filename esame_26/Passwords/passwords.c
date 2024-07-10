#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static bool CheckPassword(int* vcurr, int n) {

	int target = vcurr[0];
	for (int i = 1; i < n; ++i) {
		if (vcurr[i] != target) {
			target = vcurr[i];
		}
		else {
			return true; 
		}
	}

	return false; 
}

static void PasswordsRec(int n, int i, int last, int* vcurr, int* nsol) {
	if (i == n) {
		if (CheckPassword(vcurr, n)) {
			(*nsol)++; 
			printf("%d) ", *nsol); 
			for (int j = 0; j < n; ++j) {
				printf("%d", vcurr[j]);
			}
			printf("\n"); 
		}
		return;
	}

	for (int k = last; k < 10; ++k) {
		vcurr[i] = k;
		PasswordsRec(n, i + 1, k, vcurr, nsol); 
	}
}


void Passwords(int n) {
	if (n <= 1) {
		return; 
	}
	int* vcurr = calloc(n, sizeof(int)); 
	int nsol = 0; 

	PasswordsRec(n, 0, 0, vcurr, &nsol); 
	free(vcurr); 
}