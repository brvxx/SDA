#include <stdio.h>

extern void ToUpper(char* str);

int main(void) {

	char str[] = "prova di stringa";

	ToUpper(str);
	printf("la nuova stringa e': %s", str);
	

	return 0;
}