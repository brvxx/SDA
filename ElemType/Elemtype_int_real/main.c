// Riscrittura del programma di ordinamento degli int ma generalizzato ad elemtype 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "elemtype.h"

typedef struct {
	size_t capacity;	// capacità totale del vettore, ossia quanti elementi posso inserire all'interno del vettore al massimo 
	size_t size;		// numero di elementi effettivamente contenuti nel vettore
	ElemType* data;		// puntatore a zona di memoria contenente i veri elementi del vettore
} vector;


void PushBack(vector* v, const ElemType* e) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(ElemType));
	}
	v->data[v->size] = ElemCopy(e);
	(v->size)++;
}

void NaiveSort(vector* v) {
	for (int i = 0; i < v->size; ++i) {
		size_t minpos = i;
		for (int j = i + 1; j < v->size; ++j) {
			if (ElemCompare(v->data + j, v->data + minpos) < 0) {
				minpos = j;
			}
		}
		if (i != minpos) {
			ElemSwap(v->data + i, v->data + minpos);
		}
	}
}

int main(void) {

	vector v = {
		.capacity = 1,
		.size = 0,
		.data = malloc(sizeof(int))
	}; 

	ElemType arr[] = { -1 , 10, 9, 3, 5, 7, 8, 14, 1, 0 };

	// creo un array statico di int per effettuare la pushback perché la funzione accetta puntatori a elemtype e rand() creerebbe problemi generado warnings

	for (int i = 0; i < 10; ++i) {	
		PushBack(&v, arr + i);
	}

	NaiveSort(&v);

	printf("la sequenza ordinata e': \n");
	for (int j = 0; j < v.size; j++) {
		printf("%d ", v.data[j]);
	}

	free(v.data);
	return 0;
}