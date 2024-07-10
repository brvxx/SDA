#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int* vcurr, int* vbest, size_t i, int* max, int cnt, int sum, int* calls) {
	(*calls)++;

	if (i == pacchi_size) {		//solution found
		if (sum <= p) {
			if (cnt >= *max) {
				memcpy(vbest, vcurr, pacchi_size * sizeof(int));
				*max = cnt;
			}
		}
		return;	
	}
	
	// pruning 1) if the current number of packets plus the maximum number of packets that can be added from now on without taking the current 
	// one is less than the number of packets of the current optimal solution, then not taking this packet will make no sense; In fact all the 
	// solutions resulting from this call will have fewer packets than the optimal one, so they will not be considerate. 
	if ((int)(cnt + pacchi_size - (i + 1)) > *max) {
		vcurr[i] = 0;
		BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, i + 1, max, cnt, sum, calls);
	}

	// pruning 2) if the current sum plus the weight of the package we are going to add is greater than the target, it makes no sense to add
	// the current package and continue with the recursion, in fact all the solutions deriving from this call will have an overall weight 
	// greater than the target and therefore will not be considered valid.
	if ((sum + pacchi[i]) <= p) {		
		vcurr[i] = 1;
		BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, i + 1, max, cnt + 1, sum + pacchi[i], calls);
	}
	

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	int* vcurr = calloc(pacchi_size, sizeof(int));
	int* vbest = calloc(pacchi_size, sizeof(int));
	int cnt = 0; 
	size_t i = 0; 
	int sum = 0; 
	int max = 0; 
	int calls = 0; 


	BabboNataleRec(pacchi, pacchi_size, p, vcurr, vbest, i, &max, cnt, sum, &calls);

	for (size_t h = 0; h < pacchi_size; ++h) {
		printf("%d ", vbest[h]);
	}
	printf("\n\n totale di chiamate a fz: %d", calls);

	free(vbest);
	free(vcurr);
	return;
}