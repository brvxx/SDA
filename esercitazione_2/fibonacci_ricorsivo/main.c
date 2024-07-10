#include <stdio.h> 

extern int Fibonacci(int n);

int main(void) {

	int n = 6;
	int res = Fibonacci(n);

	printf("il valore della sequenza fibonacci in posizione %d e': %d", n, res);

	return 0; 
}