#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void SpringArragementsRec(const char* record, int* nsol, int unk, int i, int* v_curr) {
	if (i == unk) {
		(*nsol)++; 
		size_t j = 0; 
		for (size_t i = 0; i < strlen(record); ++i) {
			if (record[i] == '?') {
				if (v_curr[j] == 1) {
					printf("."); 
					++j; 
				}
				else { //v_curr[j] == 0
					printf("#");
					++j;
				}
			}
			else {
				printf("%c", record[i]); 
			}
			if (i == strlen(record) - 1) {
				printf("\n"); 
			}
		}
		return; 
	}

	v_curr[i] = 0; 
	SpringArragementsRec(record, nsol, unk, i + 1, v_curr);
	v_curr[i] = 1; 
	SpringArragementsRec(record, nsol, unk, i + 1, v_curr);

}


int SpringArrangements(const char* record) {
	int nsol = 0; 
	int unk = 0; // numero di punti di domanda dentro la stringa 
	
	// calcolo i punti di domanda all'interno della stringa
	for (size_t i = 0; i < strlen(record); ++i) {
		if (record[i] == '?') {
			++unk; 
		}
	}
	int* vcurr = calloc(unk, sizeof(int));
	SpringArragementsRec(record, &nsol, unk, 0, vcurr); 
	free(vcurr); 
	return nsol; 
}