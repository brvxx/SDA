#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void numeri_feliciRec(int num) {
	if (num == 0 || num == 4) {
		printf("Infelice"); 
		return; 
	}
	if (num == 1) {
		printf("Felice");
		return; 
	}

	int new = 0; 
	while (num > 0) {
		int tmp = num % 10;
		new += (int)pow(tmp, 2); 
		num /= 10; 
	}
	numeri_feliciRec(new); 
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

	numeri_feliciRec(num);

	return 0; 
}