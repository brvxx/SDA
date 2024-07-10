#include <stdio.h>

extern int Minimo(const int* v, int v_size);

int main(void) {

	int v[] = { 43, 12, 77, 1, 90 };
	int res = Minimo(v, 5);

	printf("il valore minimo della sequenza e': %d", res);


	return 0;
}