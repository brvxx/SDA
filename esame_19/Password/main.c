#include <stdio.h>

extern int Password(const char* str, int n);

int main(void) {

	char str[] = "a1"; 
	int n = 2; 

	int res = Password(NULL, n);
	printf("numero totale di soluzioni: %d", res); 

	return 0; 
}