#include <stdlib.h>
#include <stdio.h>

int LunghezzaVettoreRic(int* v, size_t i) {

	if (i == 0) {
		return 0; 
	}

	return 1 + LunghezzaVettoreRic(v, i - 1);
}



int main(void) {

	size_t i = 5;
	int v[] = { 1, 2, 3, 4, 5 };
	int res = LunghezzaVettoreRic(v, i);

	printf("la lunghezza del vettoere e': %d", res);

	return 0;
}