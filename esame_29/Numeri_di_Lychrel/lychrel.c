#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindromo(char* str, int* num) {
	char buff[50] = { 0 };	//stringa temporanea di appoggio 
	
	size_t str_len = strlen(str); 

	size_t j = str_len - 1; 
	for (size_t i = 0; i < str_len; i++) {
		buff[i] = str[j]; 
		--j; 
	}
	if (strcmp(buff, str) == 0) {
		return true; 
	}
	char* endptr; 
	*num = strtol(buff, &endptr, 10); 
	return false; 
}

static void Lychrel(int num, int i) {
	if (i == 0) {
		printf("Lychrel");
		return;
	}
	
	char buf[50] = { 0 };		// buffer temporaneo in cui mettere la stringa corrispondente di num 
	sprintf(buf, "%d", num);

	int num1 = 0;				// numero dato dalle cifre di num ma invertite
	palindromo(buf, &num1);		// aggiorniamo la variabile num1 con l'inverso di num 
	
	num += num1; 
	sprintf(buf, "%d", num);	// mettiamo il nuovo numero nella stringa buf

	bool palindrome = palindromo(buf, &num1);
	if (palindrome) {
		printf("Non di Lychrel");
		return; 
	}

	Lychrel(num, i - 1); 
}

int main(int argc, char** argv) {
	if (argc != 3) {
		return 1; 
	}

	char* endptr; 
	int num = strtol(argv[1], &endptr, 10);
	if (*endptr != 0 || num < 0) {
		return 1; 
	}
	int i = strtol(argv[2], &endptr, 10); 
	if (*endptr != 0) {
		return 1;
	}

	Lychrel(num, i); 

	return 0; 

	}