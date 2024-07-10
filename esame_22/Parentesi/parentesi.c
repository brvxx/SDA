#include <stdlib.h> 
#include <stdbool.h>
#include <stdio.h>

static bool CheckParentesi(int* vcurr, int n) {
	int opened = 0; 
	int closed = 0; 
	for (int i = 0; i < n; ++i) {
		if (vcurr[i] == 1) {
			opened++; 
		}
		else {
			closed++; 
		}
		if (closed > opened) {
			return false; 
		}
	}
	if (opened == closed) {
		return true;
	}
	else {
		return false; 
	}
}

static void ParentesiRec(int n, int i, int cnt, int* vcurr, int* nsol) {
	if (cnt == n) {
		if (CheckParentesi(vcurr, n * 2)) {
			(*nsol)++;
			for (int j = 0; j < n * 2; ++j) {
				vcurr[j] ? printf("(") : printf(")");
			}
			printf("\n"); 
		}

		return; 
	}
	if (i == n * 2) {
		return; 
	}
	vcurr[i] = 0; 
	ParentesiRec(n, i + 1, cnt, vcurr, nsol); 

	vcurr[i] = 1; 
	ParentesiRec(n, i + 1, cnt + 1, vcurr, nsol); 
	vcurr[i] = 0;
}

int Parentesi(int n) {
	if (n < 0) {
		return -1; 
	}
	if (n == 0) {
		return 0; 
	}
	int nsol = 0; 
	int* vcurr = calloc(n * 2, sizeof(int)); 

	ParentesiRec(n, 0, 0, vcurr, &nsol); 
	
	free(vcurr); 
	return nsol; 
}