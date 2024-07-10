#include <math.h>
#include <limits.h>

int DivisioneNegativiRec(int a, int b) {

	if (b > a) {
		return 0;
	}

	return 1 + DivisioneNegativiRec(a - b, b);
}

int DivisioneNegativi(int a, int b) {

	int sgn; 
	int a1 = abs(a);
	int b1 = abs(b); 

	if (b == 0) {
		return INT_MAX;
	}
	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		sgn = -1;
	}
	else {
		sgn = 1;
	}
	return sgn * DivisioneNegativiRec(a1, b1);
}