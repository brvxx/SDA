// Tutto nasce dalla necessità di definire un tipo generico in modo tale che si possano definire certe 
// operazioni che non dipendano dal tipo di dato con cui dobbiamo operare. Ossia che a prescindere del tipo 
// di dato con cui si ha a che fare (int, vettori, struct, ...) noi abbiamo delle funzioni definite a priori 
// che ci permettano di lavorare su il tipo generico Elemtype che può essere un qualsiasi tipo già definito 
//
// Partiamo da un esempio concreto di problema: ordinamento 

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
	size_t capacity;	// capacità totale del vettore, ossia quanti elementi posso inserire all'interno del vettore al massimo 
	size_t size;		// numero di elementi effettivamente contenuti nel vettore
	int* data;			// puntatore a zona di memoria contenente i veri elementi del vettore
} vector;

void PushBack(vector* v, int e) {	// funzione che inserisce (push) un elemento alla fine della nostra struttura dati (back) 
	
	if (v->size == v->capacity) {	// vuol dire che non ho più spazio per inserire gli elementi --> devo riallocare memoria 
		v->capacity *= 2;			// aumentassi di 1 la size ogni volta renderei l'operazione troppo costosa --> troppe realloc 
		v->data = realloc(v->data, v->capacity * sizeof(int)); 
	}
	v->data[v->size] = e; // aggiungo l'elemeto in fondo al vettore
	(v->size)++; 
}

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void NaiveSort(vector *v) {		// algoritmo di ordinamento (si tratta del selection sort) 
	for (int i = 0; i < v->size; ++i) {
		size_t minpos = i; 
		for (int j = i + 1; j < v->size; ++j) { // sicuramente i primi i sono ordinati e non ha senso confrontare un numero con se stesso --> j = i + 1 
			if (v->data[j] < v->data[minpos]) {
				minpos = j; 
			}
		}
		if (i != minpos) {
			swap(v->data + i, v->data + minpos); // equivalente ad usare &(v->data[i]) ed &(v->data[minpos]), infatti v->data punta al primo 
		}										 // elemento del vettore, se aggiungo i questo punterà all'iesimo elemento 
	}
}

int main(void) {

	vector v = {
		.capacity = 1,
		.size = 0,
		.data = malloc(sizeof(int))
	}; // inizializzo un vettore con spazio disponibile 1 ma con ancora 0 zero elementi al suo interno 
	
	srand(time(NULL));
	// la funzione srand serve per fornire alla funzione "randomizzatrice" rand un seme da cui iniziare la generazione casuale 
	// di numeri, allora per cercare di rendere la cosa più generale possible le passiamo il numero di secondi dal Epoch, così
	// che ogni volta che eseguiamo il programma questo partirà con un seme diverso 

	for (int i = 0; i < 10; ++i) { // andiamo a riempire il vettore con 20 elementi
		PushBack(&v, rand()); 
	}

	NaiveSort(&v); 

	printf("la sequenza ordinata e': \n");
	for (int j = 0; j < v.size; j++) {
		printf("%d ", v.data[j]); 
	}
	
	free(v.data);
	return 0; 
}