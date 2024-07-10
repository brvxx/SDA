#include <stdbool.h>
#include <stdio.h>

bool in(int* v, int dim, int b) {

	if (v[0] == b) {
		return true; 
	}
	else if (dim == 0) {
		return false;
	}

	return in(v + 1, dim - 1, b);
}

int main(void) {

	int val = 50; 
	int v[] = { 1, 14, 50, 38, 70 };

	bool res = in(v, 5, val);

	printf("%s", res ? "il numero e' presente nella sequenza" : "il numero non e' presente nella sequenza");

	return 0; 
}