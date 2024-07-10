#include <stdio.h>

extern unsigned long long Fattoriale(int n);

int main(void) {

	int n = 5; 
	unsigned long long res = Fattoriale(n);

	printf("il fattoriale di %d e': %llu", n, res);


	return 0; 
}