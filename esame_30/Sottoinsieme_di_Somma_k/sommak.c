#include <stdlib.h>
#include <stdio.h>

static int nsol = 0; 
static int calls = 0; 

void SommaK_rec(int n, int k, int sum_curr, int remaning, int i, int* v_curr) {
	calls++;
	if (sum_curr == k) {
		nsol++;
		/*printf("{");
		for (int j = 0; j < n; ++j) {
			if (v_curr[j] == 1) {
				printf("%d, ", j + 1);
			}
		}
		printf("}, ");*/
		return;
	}

	if (i > n - 1) {
		return;
	}

	if (sum_curr + (remaning - i - 1) >= k) {
		v_curr[i] = 0;
		SommaK_rec(n, k, sum_curr, remaning - i - 1, i + 1, v_curr);
	}
	if (sum_curr + i + 1 <= k) {
		v_curr[i] = 1;
		SommaK_rec(n, k, sum_curr + i + 1, remaning - i - 1, i + 1, v_curr);
		v_curr[i] = 0;
	}
	
}


int SommaK(int n, int k) {
	nsol = 0; 
	calls = 0; 
	int* v_curr = calloc(n, n * sizeof(int));  
	
	int sum_tot = 0; 
	for (int i = 1; i <= n; ++i) {
		sum_tot += i; 
	}
	SommaK_rec(n, k, 0, sum_tot, 0, v_curr);

	printf("numero chiamate ricorsive: %d", calls);
	free(v_curr); 
	return nsol; 
}