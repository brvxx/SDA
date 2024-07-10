#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorrenze <s> <c>\"");
		return 1; 
	}

	char c = argv[2][0];
	size_t len_str = strlen(argv[1]);
	size_t occ = 0; 

	for (size_t i = 0; i < len_str; ++i) {
		if (argv[1][i] == c) {
			++occ;
		}
	}

	printf("%zu", occ);
	return 0;
}