#include <stdlib.h>
#include <stdio.h>

int LeonardoRec(int num) {
	if (num == 0) {
		return 1; 
	}
	if (num == 1) {
		return 1; 
	}

	return  LeonardoRec(num - 1) + LeonardoRec(num - 2) + 1; 
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

	for (int i = 0; i <= num; ++i) {
		int tmp = LeonardoRec(i); 
		printf("%d, ", tmp); 
	}

	return 0; 
}