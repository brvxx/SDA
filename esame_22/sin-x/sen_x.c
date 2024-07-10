#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double factorial(double n) {
	if (n == 0 || n == 1) {
		return 1; 
	}
	return n * factorial(n - 1);
}

static double SinRec(int n, double x) {
	if (n == -1) {
		return 0; 
	}

	return (pow(-1, n) / factorial(2 * n + 1)) * pow(x, 2 * n + 1) + SinRec(n - 1, x); 
}

int main(int argc, char** argv) {
	if (argc != 3) {
		return 1; 
	}
	char* endptr; 
	double x = strtod(argv[1], &endptr); 
	
	int i = strtol(argv[2], &endptr, 10); 
	if (*endptr != 0 || i < 0) {
		return 1; 
	}

	double res = SinRec(i, x); 

	printf("%.6f", res);

	return 0; 
}