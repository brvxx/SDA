#include <stdio.h>

void SubsetK(int n, int k, int i, int count, int* vcurr, int* nsol, int* calls) {
	(*calls)++;

	if (count == k) {
		printf("%d) [", *nsol);
		(*nsol)++; 

		for (int j = 0; j < i; ++j) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; ++j) {
			printf("0 ");
		}
		puts("]\n");

		return;						//return only if we reached the expected elements -> we found a solution
	}

	if (i == n) {
		return;						//return because we reached the end of the array without the expected elements -> it won't be printed because it's not a solution 
	}
	
	if (count + n - i < k) {		//if the sum of the current count of elements taken plus n - i (the total elements minus the index of the array solution), 
		return;						//so basically the maximum number of a solution reachable is minor to k (the expected number of elements in a solution(subset)) we can 
	}								//directly close the node because any future choices made from this node onwards will not lead to solutions

	for (int j = 0; j < 2; ++j) {
		vcurr[i] = j; 

		if (j == 1) {
			++count;
		}
		SubsetK(n, k, i + 1, count, vcurr, nsol, calls);
	}

}

int main(void) {

	int elems = 10; 
	int k = 5; 
	int i = 0; 
	int count = 0; 
	int sln[10] = { 0 }; 
	int nsln = 0; 
	int calls = 0; 

	printf("i possibili sottoinsiemi di %d elementi di classe %d sono: \n", elems, k);
	SubsetK(elems, k, i, count, sln, &nsln, &calls);
	printf("totale sottoinsiemi: %d \ntotale chiamate ricorsive: %d \n", nsln, calls);




	return 0; 
}