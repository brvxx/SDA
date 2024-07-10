#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int CompareChars(const void* a, const void* b) {
	int int_a = *(const char*)a;
	int int_b = *(const char*)b;
	return (int_a > int_b) - (int_a < int_b);
}
void GetNumbers(const char* digits, int* high, int* low) {
	
	char* digits_copy = malloc(4);
	memcpy(digits_copy, digits, 4);
	
	qsort(digits_copy, 4, sizeof(char), CompareChars); // Sort the digits
	char rev_digits[4] = { digits_copy[3], digits_copy[2], digits_copy[1], digits_copy[0] }; // Copy reversed
	
	char* endptr;
	*high = strtol(rev_digits, &endptr, 10);
	*low = strtol(digits_copy, &endptr, 10);
	free(digits_copy);
}

void KapreKarRec(char* str) {

	printf("%s ", str); 

	if (strcmp(str, "6174") == 0) {
		return; 
	}

	int high = 0; 
	int low = 0; 
	int sol = 0; 

	GetNumbers(str, &high, &low);

	sol = high - low; 
	
	// trasformazione del numero in stringa
	sprintf(str, "%04d", sol);

	KapreKarRec(str); 
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1; 
	}

	int str_len = (int)strlen(argv[1]);

	char* endptr;
	int num = strtol(argv[1], &endptr, 10);
	if (*endptr != 0 || num < 0) {
		return 1;
	}
	
	char* str = NULL; 
	if (str_len > 4) {
		printf("Invalid number");  
		return 0; 
	}
	else {
		str = calloc(5, sizeof(char)); 
		// effettuiamo il padding del numero ottenuto 
		sprintf(str, "%04d", num); 
	}

	bool test = true;
	for (size_t i = 1; i < 4; i++) {
		if (str[i] != str[0]) {
			test = false; 
			break; 
		}
	}
	if (test) {
		printf("Invalid number");
		return 0;
	}


	KapreKarRec(str);

	return 0; 
}