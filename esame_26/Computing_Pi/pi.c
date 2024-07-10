#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static double pi(int n) {
	if (n == 0) {
		return 4; 
	}

	return (4 * pow(-1, n)) / (2 * n + 1) + pi(n - 1);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1; 
	}

	char* endptr; 
	int num = strtol(argv[1], &endptr, 10);
	
	if (*endptr != 0 || num < 0) {
		return 1; 
	}
	
	double res = pi(num); 

	printf("%.6lf", res);

	return 0; 
}