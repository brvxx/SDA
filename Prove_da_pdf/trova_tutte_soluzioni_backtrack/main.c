#include <stdio.h>
#include <stdlib.h>

void BacktrackTutte(int n, int k, int i, int* vcurr, int* nsol) {      // n = number of "levels" of the tree, k = number of possible choices every node
																	   // i is the index which tells us in which level we are, vcurr[] is the sequence which represent 
	if (i == n) {													   // all the choices taken till the end so it will be considered a particular solution of the problem
																	   // nsol is a variable that keeps track of the amount of solution generated 
		printf("%d)  [", *nsol);
		(*nsol)++;
		
		for (int j = 0; j < n; ++j) {				
			printf("%d ", vcurr[j]);
		}
		puts("]\n");

		return;
	}

	for (int j = 0; j < k; ++j) {									    
		vcurr[i] = j;

		BacktrackTutte(n, k, i + 1, vcurr, nsol);						// recursive approch -> backtrack algorithm 
	}
}

int main(void) {

	int lvls = 5; 
	int choices = 5;
	int i = 0; 
	int sol[] = { 0, 0, 0, 0, 0 };
	int nsol = 0;
	
	puts("possibili soluzioni decisionali al problema:\n");
	BacktrackTutte(lvls, choices, i, sol, &nsol);
	printf("soluzioni totali ammesse: %d\n", nsol);

	return 0; 
}