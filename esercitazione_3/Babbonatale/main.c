#include <stdio.h>
#include <stdlib.h>

extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);

int main(void) {

	const int pacchi[] = { 1, 2, 20, 10, 15, 13, 100, 23, 49, 30, 5 };
	size_t pacchi_size = 11;
	int p = 100; 

	printf("la slitta potrebbe contenere i seguenti pacchi regalo: \n\n");
	BabboNatale(pacchi, pacchi_size, p);


	return 0; 
}