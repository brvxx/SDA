// Questo file contiene tutte le implementazioni delle funzioni usate per lavorare con il tipo di dato ElemType

#include <string.h>

#include "elemtype.h"


// funzione di copia di un int, ovviamente non deve far niente, se non ritornare il valore passato

ElemType ElemCopy(const ElemType* e) {
	return *e;
}



// funzione che effettua il confronto tra int restituendo i valori seguendo la logica della strcmp
// se a < b ritorna - 1
// se a > b ritorna 1 
// se a = b ritorna 0 

int ElemCompare(const ElemType* a, const ElemType* b) {

	if (*a < *b) {
		return -1;
	}
	else if (*a > *b) {
		return 1;
	}
	return 0;

	// oppure più compatto: return (*a > *b) - (*a < *b), che sostanzialmente valuta le due espressioni e 
	// le sottrae, dunque se a == b avremo 0 - 0 = 0; se a < b avremo 0 - 1 = - 1 e se a > b avremo 1 - 0 = 1 
	// esattamente come volevamo 
}



// funzione che effettua lo swap tra int

void ElemSwap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}



// funzione che scrive su file l'elemento e

void ElemWrite(const ElemType* e, FILE* f) {
	fprintf(f, "%d", *e); 
}



// funzione che scrive su stdout l'elemento e, "appoggiandosi" alla ElemWrite
void ElemWriteStdout(const ElemType* e) {
	ElemWrite(e, stdout);
}



// funzione che libera la memoria

void ElemDelete(ElemType* e) {}