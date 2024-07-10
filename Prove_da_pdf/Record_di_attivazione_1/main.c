#include <stdio.h>
#include <stdlib.h>

void proc1(int a, int b, int* c) {
	int d;
	d = a + 1; a = b - 2; *c = b; b = (*c) - d;
	return;
}

char funz1(int x, int* y) {
	int* z;
	z = (int*)malloc(sizeof(int));
	*y = x + 2;
	*z = *y - x;
	proc1(x + 1, *y, z);
	printf("valori x: %d, y:%d, z:%d\n", x, *y, *z);
	return *z;
}

char funz2(int a1, int* a2) {
	int* a3;
	a3 = (int*)malloc(sizeof(int));
	*a3 = (*a2);
	proc1(a1, *(a2), a3);
	printf("valori a1: %d, a2:%d, a3:%d\n", a1, *a2, *a3);
	return *a3;
}

void main() {
	int a = 3, b = 4, c = 0, i;
	for (i = 0; i < 3; i = i + 2)
		c += funz1(a++, &b);
	a = funz2(c, &a);
	printf("scrivi a:%d, b:%d, c:%d \n", a, b, c);
	return;
}