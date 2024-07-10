#include <stdio.h>

extern int DivisioneNegativi(int a, int b);

int main(void) {

	int a = -37; 
	int b = -7;

	int res = DivisioneNegativi(a, b);

	printf("il risultato della divisione %d/%d e': %d", a, b, res);

	return 0;
}