#include <stdio.h>

extern int SommaK(int n, int k);

int main(void) {

	int n = 100; 
	int k = 100; 

	int res = SommaK(n, k); 
	/*printf("\nnumero soluzioni accettabili: %d", res); */

	return 0; 
}