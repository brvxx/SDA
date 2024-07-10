#include <stdio.h>

void CarrelloBacktrack(int n, int i, int* vcurr, int* w, int sum, int goal, int* nsol, int* calls) {

	(*calls)++;

	if (sum == goal) {			//solution found
		printf("%d) [", *nsol);
		(*nsol)++;
		
		for (int j = 0; j < i; ++j) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; ++j) {
			printf("0 ");
		}
		puts("] \n");
		return; 
	}

	if (sum > goal) {
		return;
	}
	
	if (i == n) {
		return;
	}

	for (int j = 0; j < 2; ++j) {
		vcurr[i] = j;
		if (j == 1) {
			sum += w[i];
		}
		CarrelloBacktrack(n, i + 1, vcurr, w, sum, goal, nsol, calls);
	}

}

int main(void) {

	int elems = 4; 
	int i = 0; 
	int sln[4] = { 0 };
	int weights[] = { 11 , 24 , 7, 13 };
	int sum = 0;
	int goal = 31; 
	int nsol = 0; 
	int calls = 0;

	printf("possibili carrelli con un costo di %d: \n\n", goal);
	CarrelloBacktrack(elems, i, sln, weights, sum, goal, &nsol, &calls);
	printf("i totali carrelli possibli sono quindi %d, totale chiamate a funzione : %d \n\n ", nsol, calls);


	return 0; 
}