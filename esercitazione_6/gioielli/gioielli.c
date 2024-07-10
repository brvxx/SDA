#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "gioielli.h"

int compar(const void* a, const void* b) {
	const Gioiello* pa = a;
	const Gioiello* pb = b;
	if (pa->peso/pa->prezzo < pb->peso/pb->prezzo) {
		return 1;
	}
	else if (pa->peso / pa->prezzo > pb->peso / pb->prezzo) {
		return -1;
	}
	else {
		return 0;
	}
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL; 
	} 
	
	Gioiello* gioielli = NULL;
	Gioiello tmp; 
	size_t i; 
	
	for (i = 0; fscanf(f, "%d %f %f", &tmp.codice, &tmp.peso, &tmp.prezzo) == 3; ++i) {
		gioielli = realloc(gioielli, (i + 1) * sizeof(Gioiello));
		gioielli[i] = tmp; 
	}
	
	qsort(gioielli, i, sizeof(Gioiello), compar);

	Gioiello* res = NULL; 
	size_t num_gioielli = 0; 
	for (size_t j = 0; j < i && budget != 0; ++j) {
		if (gioielli[j].prezzo <= budget) {
			res = realloc(res, (j + 1) * sizeof(Gioiello));
			res[num_gioielli] = gioielli[j]; 
			budget -= res[j].prezzo;
			++num_gioielli;
		}
	}
	*ret_size = num_gioielli; 

	fclose(f);
	free(gioielli);
	return res; 
}