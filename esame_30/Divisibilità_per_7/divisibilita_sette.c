#include <stdio.h>
#include <stdlib.h>

void div_seven_rec(int num) {
	if (num < 10) {
		if (num == 7 || num == 0) {
			printf("Multiplo di 7.");
			return; 
		}
		else {
			printf("Non multiplo di 7.");
			return; 
		}
	}
	
	int a = num / 10; 
	int b = 2 * (num % 10); 
	num = abs(a - b); 

	div_seven_rec(num); 

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

	div_seven_rec(num); 

	return 0; 
}