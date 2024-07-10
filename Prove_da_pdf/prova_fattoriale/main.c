#include <stdio.h>

int fattoriale(int a) {
	int prod = 1; 
	/*int tmp = a + 1; 
	while (--tmp > 0) {
		prod *= tmp; 
	}*/
	for (int i = 1; i <= a; ++i) {
		prod *= i;
	}
	
	return prod; 
}


int main(void) {

	int x = 5, res;
	res = fattoriale(x++);
	
	printf("il fattoriale di %d e': %d", x, res);

	return 0; 

}