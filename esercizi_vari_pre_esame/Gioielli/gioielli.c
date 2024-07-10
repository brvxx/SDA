#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 

#include "gioielli.h"

// la funzione qsort ordina in modo crescente, quindi dati due elementi 
// a e b, se la compare ritorna -1 significa che a è più piccolo di b e 
// quindi andrà messo prima, dunque noi volendo ordinare in senso decrescente,
// quello che andremo a fare è semplicemente scambiare i valori di ritorno dei 
// confronti. ossia, se nella nostra idea di ordinamento di peso/prezzo, vogliamo 
// far si che un gioiello con rapporto maggiore venga messo prima rispetto ad un 
// gioiello MENO APPETIBILE con rapporto inferiore, dobbiamo far si che il confronto 
// tra il maggiore e il minore ritorni -1. 
int compare(const void* a, const void* b) {
	Gioiello* pa = (Gioiello*)a;
	Gioiello* pb = (Gioiello*)b;
	
	if (pa->peso / pa->prezzo > pb->peso / pb->prezzo) {
		return -1; 
	}
	else if (pa->peso / pa->prezzo < pb->peso / pb->prezzo) {
		return 1; 
	}
	else {
		return 0; 
	}
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	FILE* f = fopen(filename, "r"); 
	if (!f) {
		return NULL; 
	}

	Gioiello tmp = { 0 }; 
	Gioiello* gioielli = NULL; 
	size_t num = 0; 
	while (fscanf(f, "%d%f%f", &tmp.codice, &tmp.peso, &tmp.prezzo) == 3) {
		++num; 
		gioielli = realloc(gioielli, num * sizeof(Gioiello)); 
		gioielli[num - 1] = tmp; 
	}

	qsort(gioielli, num, sizeof(Gioiello), compare); 

	Gioiello* res = NULL; 
	size_t gioielli_presi = 0; 
	for (size_t i = 0; i < num; ++i) {
		if (gioielli[i].prezzo <= budget) {
			++gioielli_presi;
			res = realloc(res, gioielli_presi * sizeof(Gioiello));
			res[gioielli_presi - 1] = gioielli[i]; 
			budget -= gioielli[i].prezzo; 
		}
	}
	*ret_size = gioielli_presi; 

	fclose(f); 
	free(gioielli); 
	return res; 
}