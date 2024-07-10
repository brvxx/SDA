#include <stdio.h>

extern int Prodotto(int a, int b);

int main(void) {

	int a = 5;
	int b = 3; 

	int res = Prodotto(a, b);

	printf("il prodotto di %d e %d e': %d", a, b, res);


	return 0; 
}