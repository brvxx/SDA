#include <stdio.h>

extern int Divisione(int a, int b);

int main(void) {

	int a = 37;
	int b = 5; 

	int res = Divisione(a, b);

	printf("il risulato della divisione %d/%d e': %d", a, b, res);

	return 0;
}