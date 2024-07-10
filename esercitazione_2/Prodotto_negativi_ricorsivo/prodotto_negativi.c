#include <stdbool.h>
#include <math.h>

int ProdottoNegativiRec(int a, int b) {
	if (b == 0) {
		return 0;
	}

	return a + ProdottoNegativiRec(a, b - 1);
}

int ProdottoNegativi(int a, int b) {

	int sgn;

	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		sgn = -1;
	}
	else {
		sgn = 1;
	}

	return sgn * (ProdottoNegativiRec(abs(a), abs(b)));
}