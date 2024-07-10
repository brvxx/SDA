#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> < b>\"");
		return 1;
	}

	char* endptr;
	int prod = 0;

	int n1 = strtol(argv[1], &endptr, 10);
	if (*endptr != 0) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> < b>\"");
		return 1;
	}

	int n2 = strtol(argv[2], &endptr, 10);
	if (*endptr != 0) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> < b>\"");
		return 1; 
	}

	prod = n1 * n2;

	printf("%d", prod);
	return 0;
}