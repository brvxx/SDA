#include <stdio.h>

int sommafinoaN(int n) {
	if (n == 1) {
		return 1; 
	}
	return n + sommafinoaN(n - 1);
}


int main(void) {
	
	int sum = 0, n = 7;
	sum = sommafinoaN(n);
	printf("la somma dei primi %d numeri positivi e': %d", n, sum);
	
	return 0; 
}