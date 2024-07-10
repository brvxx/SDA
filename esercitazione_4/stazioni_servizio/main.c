#include <stdio.h>
#include <stdlib.h>

extern void StazioniServizio(double m, const double* d, const double* p, size_t n);

int main(void) {

	double dst[] = { 260, 284, 308, 332, 356 }; 
	double prezzi[] = { 35, 35, 33, 29, 23 }; 
	int m = 2500; 
	size_t n = 5; 

	StazioniServizio(m, dst, prezzi, n);

	return 0; 
}