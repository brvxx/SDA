#include <stdio.h>

extern int ProdottoNegativi(int a, int b);

int main(void) {

	int a = 5;
	int b = -3;

	int res = ProdottoNegativi(a, b);

	printf("il prodotto tra %d e %d e': %d", a, b, res);


	return 0;
}