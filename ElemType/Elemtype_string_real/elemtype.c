// Questo file invece contiene tutte le implementazioni delle funzioni usate all'interno del file principale (in questo caso main.c)

#include <string.h>

#include "elemtype.h"

// funzione di copia della string, questa crea una nuova string però questa volta con memoria allocata dinamicamente, così che 
// la stringa nel vettore avrà un char *data che punterà a questa memoria allocata dinamicamente. Ovviamente la nuova string conterrà 
// le stesse informazioni della stringa passate per indirizzo come parametro della funzione (per questo si chiama stringcopy)

ElemType ElemCopy(const ElemType* e) { 
								     
	ElemType res = {					 
		.size = e->size,
		.data = malloc(e->size * sizeof(char))
	};

	memcpy(res.data, e->data, res.size * sizeof(char));

	return res;
}

// funzione che effettua il confronto tra string (tipo da noi definito), perché non esiste una funzione che lo faccia, mentre
// con gli int ci bastava fare a < b con l'operatore confronto. Nota che questa funzione lavora esattamente come la strcmp

int ElemCompare(const ElemType* a, const ElemType* b) {	
														  

	for (size_t i = 0; i < a->size && i < b->size; ++i) {
		if (a->data[i] < b->data[i]) {
			return -1;
		}
		else if (a->data[i] > b->data[i]) {
			return 1;
		}
	}

	if (a->size < b->size) {
		return -1;
	}
	else if (a->size > b->size) {
		return 1;
	}

	return 0;	
}

// funzione che effettua lo swap tra string. Nota che in questo caso possiamo utilizzare l'assegnamento poichè sia a che b hanno i prorpi 
// data che puntano a zone di memoria allocate dinamicamente fare l'assegnamento implica che se *a = *b, allora il campo char *data di a 
// ora punta al campo char *data di b e poi a.size = b.size

void ElemSwap(ElemType* a, ElemType* b) {	
	ElemType tmp = *a;				
	*a = *b;
	*b = tmp;
}

// funzione che libera la memoria
void ElemDelete(ElemType* e) { 
	free(e->data);
}