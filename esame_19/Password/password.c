#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void PasswordRec(const char* str, int n, int i, int* vcurr, int* nsol, int len) {
	if (i == n) {
		(*nsol)++; 
		for (int j = 0; j < n; ++j) {
			printf("%c", str[vcurr[j]]); 
		}
		printf("\n"); 
		return; 
	}

	for (int k = 0; k < len; ++k) {
		vcurr[i] = k; 
		PasswordRec(str, n, i + 1, vcurr, nsol, len); 
	}
}

int Password(const char* str, int n) {
	if (!str) {
		return 0; 
	}
	int* vcurr = calloc(n, sizeof(int)); 
	int nsol = 0; 
	int len = (int)strlen(str); 

	PasswordRec(str, n, 0, vcurr, &nsol, len); 

	free(vcurr); 
	return nsol; 
}