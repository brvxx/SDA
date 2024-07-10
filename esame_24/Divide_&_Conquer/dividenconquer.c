#include <stdlib.h>
#include <stdio.h>

int divide_impera_rec(int num) {
	if (num == 0) {
		return 0; 
	}
	if (num == 1) {
		return 1; 
	}

	return divide_impera_rec(num / 2) + divide_impera_rec(num - num / 2) + num;
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

	int res = divide_impera_rec(num); 
	printf("%d", res); 

	return 0; 
}