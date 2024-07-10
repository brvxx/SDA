//spiegazioni varie su onenote (esercizi vari) 

#include <stdio.h>

void Swap(int* a, int* b) {

	int tmp; 
	
	tmp = *a; 
	*a = *b;
	*b = tmp;
}

void Permutations(int n, int i, int vcurr[], int* nsol) { 

	if (i == n) {
		printf("%d)  ( ", *nsol);
		(*nsol)++;

		for (int j = 0; j < n; ++j) {
			printf("%d ", vcurr[j]);
		}
		printf(") \n");
		return; 
	}

	for (int j = i; j < n; ++j) {
		Swap(vcurr + i, vcurr + j);
		Permutations(n, i + 1, vcurr, nsol);
		Swap(vcurr + i, vcurr + j);
	}
}

int main(void) {

	int n = 3;
	int i = 0; 
	int v[] = { 1, 2 ,3 };
	int nsol = 0; 

	printf("possibili permutazioni di: ( ");
	
	for (int i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}
	printf(")\n\n");

	Permutations(n, i, v, &nsol);
	printf("\nil numero totale di permutazioni e': %d, ossia %d!\n\n", nsol, n);

	return 0; 
}