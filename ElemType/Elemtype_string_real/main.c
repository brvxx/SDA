// Questo programma è sostanzialmente una riscrittura di quello precedente, solo che andiamo a rendere effettivo tutto 
// quello che abbiamo detto sul tipo di dato elemtype. Dunque, per svoglere lo stesso compito ma con un tipo di dato 
// qualsiasi, quello che faremo sostanzialmente sarà mantenere l'algoritmo e cambiare solo le implementazioni delle funzioni 
// che lavorano con il tipo di dato specifico, così da rendere un programma che sfrutta certi algoritmi, universale per ogni 
// tipo di dato 


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
		.data = malloc(sizeof(ElemType))
	};  

	ElemType arr[] = { {6, "parola"}, {5 , "mamma"}, {5, "gatto"} , {7, "gattone"} }; 

	for (int i = 0; i < 4; ++i) {  
		PushBack(&v, arr + i);
	}

	NaiveSort(&v);

	printf("la sequenza ordinata di ElemType e': \n");
	for (size_t j = 0; j < v.size; j++) {
		for (size_t k = 0; k < (v.data[j]).size; ++k) {
			putc((v.data[j]).data[k], stdout);
		}
		printf("\n");
	}

	for (size_t l = 0; l < v.size; ++l) {
		ElemDelete(v.data + l); 
	}
	free(v.data);

	return 0;
}


// duqnue adesso se volessi passare da tipo string a int nuovamente il main praticamente non lo dovrei andare a toccare, devo solo cambiare le varie 
// implementazioni delle funzoni nel file elemtype.c