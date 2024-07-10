// in questo caso stiamo sempre cercando di andare ad effettuare un ordinamento, ma non di integer, bensì di un tipo da noi definito. 
// ci renderemo facilemnte conto del fatto che il procedimento rimane lo stesso di quello usato per gli int, quello che cambia è la 
// differente implementazione delle varie funzioni ausiliarie --> da qui nasce la necessità dell'utilizzo del generico elemento, ossia 
// l'Elementtype 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	size_t size;		// lunghezza della stringa
	char* data;			// vettore di char
} string;

typedef struct {
	size_t capacity;	// capacità totale del vettore, ossia quanti elementi posso inserire all'interno del vettore al massimo 
	size_t size;		// numero di elementi effettivamente contenuti nel vettore
	string* data;		// puntatore a zona di memoria contenente i veri elementi del vettore
} vector;

string StringCopy(const string* e) { // funzione di copia della string, questa crea una nuova string però questa volta con memoria allocata dinamicamente, così che 
									 // la stringa nel vettore avrà un char *data che punterà a questa memoria allocata dinamicamente. Ovviamente la nuova string conterrà 
	string res = {					 // le stesse informazioni della stringa passate per indirizzo come parametro della funzione (per questo si chiama stringcopy)
		.size = e->size,
		.data = malloc(e->size * sizeof(char))
	};

	memcpy(res.data, e->data, res.size * sizeof(char));
	
	return res; 
}

int StringCompare(const string* a, const string* b) {	// ci serve per effettuare il confronto tra string (tipo da noi definito), perché non esiste una funzione che lo faccia, mentre
														// con gli int ci bastava fare a < b con l'operatore confronto. Nota che questa funzione lavora esattamente come la strcmp  
	
	for (size_t i = 0; i < a->size && i < b->size; ++i) {
		if (a->data[i] < b->data[i]) {
			return -1; 
		}
		else if (a->data[i] > b->data[i]) {
			return 1; 
		}
	}
	
	// se si esce dal for senza essere ritornati al chiamante significa che fino a min{ a->size, b->size } le stringhe sono uguali, allora bisogna determinare quale 
	// delle due è più lunga per determinare quale delle due sia la maggiore 
	if (a->size < b->size) {
		return -1;
	}
	else if (a->size > b->size) {
		return 1; 
	}

	return 0;	// caso in cui le stringhe sono completamente identiche 
}

void PushBack(vector* v, const string *e) { // usiamo const perché la stringa che mi serve per essere messa dentro al vettore non dovrà essere toccata (è quella nel main)
	if (v->size == v->capacity) {
		v->capacity *= 2; 
		v->data = realloc(v->data, v->capacity * sizeof(string)); 
	}
	v->data[v->size] = StringCopy(e);	// Non posso fare un semplice assegnamento tra struct, infatti se facessi in quel modo io andrei a copiare la size tranquillamente, però
										// per quanto riguarda la memoria contenente la vera stringa (ovvero char *data), andrei a copiare l'indirizzo della memoria statica del main
										// nella nuova string allocata dinamicamente, noi non vogliamo che ciò accada, vogliamo che la nuova string all'interno del vettore contenga 
										// tutte le informazioni della stringa passata alla funzione per indirizzo, però che sia completamente indipendete da essa e quindi che abbia
										// il suo puntatore a char che punti ad una zona di memoria allocata dinamicamente contenente la stessa parola (sarebbe la stringa tipo "gatto")
	(v->size)++;
}

void swap(string* a, string* b) {		// in questo caso possiamo utilizzare l'assegnamento poichè sia a che b hanno i prorpi data che puntano a zone di memoria allocate dinamicamente
	string tmp = *a;					// fare l'assegnamento implica che se *a = *b, allora il campo char *data di a ora punta al campo char *data di b e poi a.size = b.size
	*a = *b; 
	*b = tmp; 
}

void NaiveSort(vector* v) {		// algoritmo di ordinamento (si tratta del selection sort) 
	for (int i = 0; i < v->size; ++i) {
		size_t minpos = i;
		for (int j = i + 1; j < v->size; ++j) { 
			if (StringCompare(v->data + j, v->data + minpos) < 0) {   // ossia caso in cui la funzione ritorna -1, quindi la prima stringa è minore della seconda stringa passata
				minpos = j;
			}
		}
		if (i != minpos) {
			swap(v->data + i, v->data + minpos);  
		}										 
	}
}

void StringDelete(string* e) { // va liberata la memoria allocata durante le varie stringcopy
	free(e->data);
}

int main(void) {

	vector v = {
		.capacity = 1,
		.size = 0,
		.data = malloc(sizeof(string))
	}; // inizializzo un vettore con spazio disponibile 1 ma con ancora 0 zero elementi al suo interno 

	string arr[] = { {6, "parola"}, {5 , "mamma"}, {5, "gatto"} , {7, "gattone"} }; // array di stringhe, notare che l'abbiamo definita noi cos'è una stringa

	for (int i = 0; i < 4; ++i) { // andiamo a popolare il vettore la memoria data del vettore con le varie stringhe create sopra 
		PushBack(&v, arr + i); 
	}

	NaiveSort(&v);

	printf("la sequenza ordinata di string e': \n");
	for (size_t j = 0; j < v.size; j++) {
		for (size_t k = 0; k < (v.data[j]).size; ++k) {
			putc((v.data[j]).data[k], stdout);
		}
		printf("\n");
	}

	for (size_t l = 0; l < v.size; ++l) {
		StringDelete(v.data + l); // libera la memoria puntata da ogni singola string del vettore 
	}
	free(v.data);

	return 0;
}