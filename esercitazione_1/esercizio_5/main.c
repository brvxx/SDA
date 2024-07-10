#include <stdio.h>
#include <string.h>

extern int ContaOccorrenze(const char* filename, const char* str);

int main(void) {

	const char str[] = "file";
	int res = ContaOccorrenze("file2.txt", str);

	printf("il numero di occorrenze della parola \"%s\" e': %d", str, res);

	return 0; 
}