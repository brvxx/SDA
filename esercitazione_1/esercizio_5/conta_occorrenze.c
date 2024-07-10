#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int ContaOccorrenze(const char* filename, const char* str) {
	
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return 0; 
	}

	char buf[100] = { 0 };
	int occ = 0; 
	
	while (fscanf(f, "%s", buf) == 1) {
		if (strcmp(buf, str) == 0) {
			occ++;
		}
	}
	
	fclose(f);
	return occ;
} 