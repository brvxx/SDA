#include <stdlib.h>
#include <stdio.h>

static int TriangularRec(int n) {
	if (n == 0) {
		return 0; 
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3; 
	}

	int v1 = TriangularRec(n - 1);
	int v2 = TriangularRec(n - 2);
	int v3 = TriangularRec(n - 3);

	return (3 * v1) - (3 * v2) + v3; 
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

	int res = TriangularRec(num); 
	printf("%d", res); 

	return 0; 
}